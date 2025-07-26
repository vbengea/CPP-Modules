#include "Cat.hpp"

Cat::Cat() : Animal() {
	_type = "Cat";
	std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& rhs) : Animal(rhs) {
	this->_type = rhs._type;
	std::cout << "Copy Cat constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
		std::cout << "Assigment Dog constructor called" << std::endl; 
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Destructor Cat called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
