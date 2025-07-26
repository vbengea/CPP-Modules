#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
	public:
		Point(); // Constructor
		Point(Point const &src);
		Point(float const x, float const y);
		Point &operator=(Point const &rhs);
		~Point(); // Destructor

		Fixed getX() const;
		Fixed getY() const;

		bool operator==(Point const &rhs) const;

	private:
		// Add member variables here
		Fixed const x;
		Fixed const y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
Fixed calculateArea(Point const a, Point const b, Point const c);

#endif // POINT_HPP
