#include "Dog.hpp"

Dog::Dog() : Animal() {
	_type = "Dog";
	std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal(rhs){
	this->_type = rhs._type;
	std::cout << "Copy Dog constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
		std::cout << "Assignment Dog constructor called" << std::endl;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Destructor Dog called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}
