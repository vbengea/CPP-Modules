#include "Harl.hpp"

Harl::Harl() {
	// Constructor implementation
}

Harl::~Harl() {
	// Destructor implementation
}

Harl::Level Harl::getLevel(std::string level) {
	if (level == "DEBUG") {
		return DEBUG;
	}
	else if (level == "INFO") {
		return INFO;
	}
	else if (level == "WARNING") {
		return (WARNING);
	}
	else if (level == "ERROR") {
		return (ERROR);
	}
	else {
		return UNKNOWN;
	}
}

void Harl::complain(std::string level) {
	typedef void (Harl::*HarlFunction)();

	HarlFunction functions[] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string levels[] = {
		"DEBUG", 
		"INFO",
		"WARNING",
		"ERROR"
	};

	switch (getLevel(level)) {
		case DEBUG:
			(this->*functions[0])();
			break;
		case INFO:
			(this->*functions[1])();
			break;
		case WARNING:
			(this->*functions[2])();
			break;
		case ERROR:
			(this->*functions[3])();
			break;
		default:
			std::cout << "Unknown level" << std::endl;
			break;
	}
}

void Harl::debug() {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error() {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}