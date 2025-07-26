#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(); // Constructor
		Fixed(int value); // Constructor with integer
		Fixed(float value); // Constructor with float
		Fixed(const Fixed &src); // Copy constructor
		Fixed &operator=(const Fixed &rhs); // Assignment operator
		~Fixed(); // Destructor

		float toFloat() const; // Convert to float
		int toInt() const; // Convert to integer

		int getRawBits() const; // Getter for raw bits
		void setRawBits(int const raw); // Setter for raw bits


		// Arithmetic operators
		Fixed operator+(const Fixed &rhs) const;
		Fixed operator-(const Fixed &rhs) const;
		Fixed operator*(const Fixed &rhs) const;
		Fixed operator/(const Fixed &rhs) const;
		// Increment and decrement operators
		Fixed &operator++(); // Pre-increment
		Fixed operator++(int); // Post-increment
		Fixed &operator--(); // Pre-decrement
		Fixed operator--(int); // Post-decrement
		// Comparison operators
		bool operator>(const Fixed &rhs) const;
		bool operator<(const Fixed &rhs) const;
		bool operator>=(const Fixed &rhs) const;
		bool operator<=(const Fixed &rhs) const;
		bool operator==(const Fixed &rhs) const;
		bool operator!=(const Fixed &rhs) const;
		// Min and max functions
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

	private:
		// Add member variables here
		int _value; // Fixed-point value
		static const int _fractionalBits = 8; // Number of fractional bits
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP
