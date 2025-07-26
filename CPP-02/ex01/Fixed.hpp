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
	private:
		// Add member variables here
		int _value; // Fixed-point value
		static const int _fractionalBits = 8; // Number of fractional bits
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP
