#include "Animal.hpp"

Animal::Animal() : _type("") {
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& rhs) : _type(rhs._type) {
	std::cout << "Copy Animal constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	std::cout << "Assignment Animal constructor called" << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "Destructor Animal called" << std::endl;
}


void Animal::makeSound() const {
	std::cout << "Default sound." << std::endl;
}

std::string Animal::getType() const {
	return this->_type;
}

void Animal::setType(std::string type) {
	this->_type = type;
}