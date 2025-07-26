#include "Fixed.hpp"
#include <iostream>
#include <cmath>

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

Fixed::Fixed(const int value) : _value(value << _fractionalBits) {
	// Constructor with integer implementation
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(static_cast<int>(roundf(value * (1 << _fractionalBits)))) {
	// Constructor with float implementation
	std::cout << "Float constructor called" << std::endl;
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

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}

float Fixed::toFloat() const {
	return static_cast<float>(_value) / (1 << _fractionalBits); // Convert to float
}

int Fixed::toInt() const {
	return _value >> _fractionalBits; // Convert to integer
}