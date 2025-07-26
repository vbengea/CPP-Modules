#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed(); // Constructor
		Fixed(const Fixed &src); // Copy constructor
		Fixed &operator=(const Fixed &rhs); // Assignment operator
		~Fixed(); // Destructor

		int getRawBits() const; // Getter for raw bits
		void setRawBits(int const raw); // Setter for raw bits
	private:
		// Add member variables here
		int _value; // Fixed-point value
		static const int _fractionalBits = 8; // Number of fractional bits
};

#endif // FIXED_HPP
