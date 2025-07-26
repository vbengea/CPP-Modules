#include "ScalarConverter.hpp"
#include <limits.h>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <string.h>

ScalarConverter::ScalarConverter() {
	
}

ScalarConverter::ScalarConverter(const ScalarConverter& rhs) {
	(void)rhs;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
	if (this != &rhs) {
		
	}
	return *this;
}

ScalarConverter::~ScalarConverter() {
	
}

void ScalarConverter::convert(const std::string& str) {
	if (str.empty()) {
		std::cerr << "Error: Empty input" << std::endl;
		return;
	}

	InputType type = getInputType(str);

	if (type == LITERAL) {
		handleLiteral(str);
		return;
	}

	if (type == INVALID) {
		std::cerr << "Error: Invalid input" << std::endl;
		return;
	}

	double value = 0.0;

	switch (type) {
		case CHAR:
			value = static_cast<double>(str[0]);
			break;
		case INT:
			value = static_cast<double>(atoi(str.c_str()));
			break;
		case FLOAT:
			value = static_cast<double>(atof(str.c_str()));
			break;
		case DOUBLE:
			value = atof(str.c_str());
			break;
		default:
			break;
	}

	displayChar(value);
	displayInt(value);
	displayFloat(value);
	displayDouble(value);
}

InputType ScalarConverter::getInputType(const std::string& str) {
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
		return LITERAL;

	if (str.length() == 1 && !std::isdigit(str[0]))
		return CHAR;
	
	if (!str.empty() && str[str.length() - 1] == 'f') {
		std::string temp = str.substr(0, str.length() - 1);
		char* endptr;
		strtof(temp.c_str(), &endptr);
		if (*endptr == '\0') {
			return FLOAT;
		}
		return INVALID;
	}

	char* endptr;
	long val = strtol(str.c_str(), &endptr, 10);
	if (*endptr == '\0' && val >= INT_MIN && val <= INT_MAX) {
		return INT;
	}
	
	strtod(str.c_str(), &endptr);
	if (*endptr == '\0') {
		return DOUBLE;
	}

	return INVALID;
}

void ScalarConverter::handleLiteral(const std::string& str) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (str == "nan" || str == "nanf") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	} else if (str == "+inf" || str == "+inff") {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	} else if (str == "-inf" || str == "-inff") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::displayChar(double value) {
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127) {
		std::cout << "char: impossible" << std::endl;
	} else if (value < 32 || value > 126) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	}
}

void ScalarConverter::displayInt(double value) {
	if (std::isnan(value) || std::isinf(value) ||
		value < INT_MIN || INT_MAX) {
			std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
}

void ScalarConverter::displayFloat(double value) {
	if (std::isnan(value)) {
		std::cout << "float: nanf" << std::endl;
	} else if (std::isinf(value)) {
		std::cout << "float: " << (value < 0 ? "-" : "+") << "inff" << std::endl;
	} else {
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	}
}

void ScalarConverter::displayDouble(double value) {
	if (std::isnan(value)) {
		std::cout << "double: nan" << std::endl;
	} else if (std::isinf(value)) {
		std::cout << "double: " << (value < 0 ? "-" : "+") << "inf" << std::endl;
	} else {
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
	}
}