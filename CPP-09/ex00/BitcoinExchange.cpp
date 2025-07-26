#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>

BitcoinExchange::BitcoinExchange() {
	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) : data(rhs.data) {

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
	if (this != &rhs) {
		this->data = rhs.data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
	
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file " << filename << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		if (line.empty()) {
			continue;
		}

		size_t delimPos = line.find(',');
		if (delimPos == std::string::npos) {
			std::cerr << "Error: invalid line format: " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, delimPos);
		std::string value = line.substr(delimPos + 1);

		date.erase(0, date.find_first_not_of(" \t"));
		date.erase(date.find_last_not_of(" \t") + 1);
		value.erase(0, value.find_first_not_of(" \t"));
		value.erase(value.find_last_not_of(" \t") + 1);

		if (!isValidDate(date) || !isValidFloatFormat(value)) {
			std::cerr << "Error: invalid data: " << line << std::endl;
			continue;
		}

		std::istringstream iss(value);
		float floatValue;
		iss >> floatValue;

		data.insert(std::pair<std::string, float>(date, floatValue));
	}
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.length() != 10) {
		return false;
	}
	if (date[4] != '-' || date[7] != '-') {
		return false;
	}
	for (size_t i = 0; i < date.length(); i++) {
		if (i != 4 && i != 7 && !isdigit(date[i])) {
			return false;
		}
	}

	int year, month, day;
	std::istringstream iss(date);
	char dash1, dash2;
	iss >> year >> dash1 >> month >> dash2 >> day;

	if (iss.fail() || dash1 != '-' || dash2 != '-') {
		return false;
	}

	if (month < 1 || month > 12) {
		return false;
	}
	
	int daysMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		daysMonth[2] = 29;
	}
	
	return day >= 1 && day <= daysMonth[month];
}


bool BitcoinExchange::isValidFloatFormat(const std::string& str) const {
	std::istringstream iss(str);
	float value;
	iss >> value;
	return !iss.fail() && iss.eof() && value >= 0;
}

void BitcoinExchange::processInputFile(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file " << filename << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line); // skip first line

	while (std::getline(file, line)) {
		if (line.empty()) {
			continue;
		}

		size_t delimPos = line.find('|');
		if (delimPos == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string dateStr = line.substr(0, delimPos);
		std::string valueStr = line.substr(delimPos + 1);

		dateStr.erase(0, dateStr.find_first_not_of(" \t"));
		dateStr.erase(dateStr.find_last_not_of(" \t") + 1);
		valueStr.erase(0, valueStr.find_first_not_of(" \t"));
		valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

		if (!isValidDate(dateStr)) {
			std::cerr << "Error: bad input => " << dateStr << std::endl;
			continue;
		}

		std::istringstream iss(valueStr);
		float value;
		iss >> value;

		if (iss.fail() || !iss.eof()) {
			std::cerr << "Error: invalid value." << std::endl;
			continue;
		}

		if (value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}

		if (value > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		calculatePriceForEntry(dateStr, value);
	}
	file.close();
}

void BitcoinExchange::calculatePriceForEntry(const std::string& date, float value) const {
	std::map<std::string, float>::const_iterator dataIt = data.upper_bound(date);

	if (dataIt == data.begin() && dataIt->first != date) {
		std::cout << "Error: no data available for date " << date << std::endl;
		return;
	}
	
	if (dataIt->first != date && dataIt != data.begin()) {
		--dataIt;
	}

	std::cout << date << " => ";
	if (value == static_cast<int>(value)) {
		std::cout << static_cast<int>(value);
	} else {
		std::cout << value;
	}

	float result = value * dataIt->second;

	std::cout << " = ";
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(2) << result;
	std::string resultStr = oss.str();

	if (resultStr[resultStr.length() - 1] == '0') {
		resultStr.erase(resultStr.length() - 1);
	}

	std::cout << resultStr << std::endl;
}
