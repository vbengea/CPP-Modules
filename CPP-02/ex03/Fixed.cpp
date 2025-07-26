#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _value(0) {
	// Constructor implementation
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) : _value(src._value) {
	// Copy constructor implementation
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		_value = rhs._value; // Assignment operator implementation
	}
	return *this;
}

Fixed::Fixed(const int value) : _value(value << _fractionalBits) {
	// Constructor with integer implementation
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) {
	// Constructor with float implementation
	// std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << _fractionalBits));
}

int Fixed::getRawBits() const {
	// std::cout << "getRawBits member function called" << std::endl;
	return _value; // Getter for raw bits
}

void Fixed::setRawBits(int const raw) {
	_value = raw; // Setter for raw bits
}

Fixed::~Fixed() {
	// Destructor implementation
	// std::cout << "Destructor called" << std::endl;
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

Fixed Fixed::operator+(const Fixed &rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	if (rhs._value == 0) {
		std::cerr << "Error: Division by zero" << std::endl;
		return (Fixed(0));
	}
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &Fixed::operator++() {
	_value += (1 << _fractionalBits); // Pre increment
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this; // Post increment
	++(*this);
	return temp;
}

Fixed &Fixed::operator--() {
	this->_value -= (1 << _fractionalBits);
	return *this; // Pre decrement
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this; // Post decrement
	--(*this);
	return temp;
}

bool Fixed::operator>(const Fixed &rhs) const {
	return (this->toFloat() > rhs.toFloat());
}

bool Fixed::operator<(const Fixed &rhs) const {
	return (this->toFloat() < rhs.toFloat());
}

bool Fixed::operator>=(const Fixed &rhs) const {
	return (this->toFloat() >= rhs.toFloat());
}

bool Fixed::operator<=(const Fixed &rhs) const {
	return (this->toFloat() <= rhs.toFloat());
}

bool Fixed::operator==(const Fixed &rhs) const {
	return (this->toFloat() == rhs.toFloat());
}

bool Fixed::operator!=(const Fixed &rhs) const {
	return (this->toFloat() != rhs.toFloat());
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	else
		return b;
}

Fixed const &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return a;
	else
		return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	else
		return b;
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return a;
	else
		return b;
}

int Fixed::absoluteValue(int n) const {
	if (n < 0)
		return -n;
	return n;
}