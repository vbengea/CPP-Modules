#include "Animal.hpp"

AAnimal::AAnimal() : _type("") {
	std::cout << "Default Animal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& rhs) : _type(rhs._type) {
	std::cout << "Copy Animal constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	std::cout << "Assignment Animal constructor called" << std::endl;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "Destructor Animal called" << std::endl;
}


void AAnimal::makeSound() const {
	std::cout << "Default sound." << std::endl;
}

std::string AAnimal::getType() const {
	return this->_type;
}

void AAnimal::setType(std::string type) {
	this->_type = type;
}