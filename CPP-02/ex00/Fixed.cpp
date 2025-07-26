#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _value(0) {
	// Constructor implementation
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) : _value(src._value) {
	// Copy constructor implementation
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		_value = rhs._value; // Assignment operator implementation
	}
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value; // Getter for raw bits
}

void Fixed::setRawBits(int const raw) {
	_value = raw; // Setter for raw bits
}

Fixed::~Fixed() {
	// Destructor implementation
	std::cout << "Destructor called" << std::endl;
}
