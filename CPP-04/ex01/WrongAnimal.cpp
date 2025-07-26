#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Default") {
	std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs) : _type(rhs._type) {
	std::cout << "Default WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
		std::cout << "Assignment WrongAnimal constructor called" << std::endl;
	}
	return *this;
}


std::string WrongAnimal::getType() const {
	return this->_type;
}

void WrongAnimal::setType(std::string type) {
	this->_type = type;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Default WrongAnimal destructor called" << std::endl;
}


void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal Sound!" << std::endl;
}