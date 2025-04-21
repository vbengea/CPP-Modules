#include "Harl.hpp"

Harl::Harl() {
	// Constructor implementation
}

Harl::~Harl() {
	// Destructor implementation
}

void Harl::complain(std::string level) {

	std::string levels[] = {
		"DEBUG", 
		"INFO",
		"WARNING",
		"ERROR"
	};

	int i = 0;
	while (i < 4 && levels[i] != level) {
		i++;
	}

	switch (i) {
		case 0:
			this->debug();
			/* fall through */
		case 1:
			this->info();
			/* fall through */
		case 2:
			this->warning();
			/* fall through */
		case 3:
			this->error();
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