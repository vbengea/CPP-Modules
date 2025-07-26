#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	this->_type = "WrongCat";
	std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& rhs) : WrongAnimal() {
	this->_type = rhs._type;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
		std::cout << "Assignment WrongCat constructor called" << std::endl;
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "Default WrongCat constructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat sound" << std::endl;
}
