#include "Point.hpp"

Point::Point() : x(0), y(0) {
	// Constructor implementation
}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(Point const &src) : x(src.x), y(src.y) {
	// Copy constructor implementation
}

Point &Point::operator=(Point const &rhs) {
	if (this != &rhs) {
		// Assignment operator implementation
		// Note: x and y are const, so we cannot assign them here
		(void)rhs;
		return *this;
	}
	return *this;
}

Point::~Point() {
	// Destructor implementation
}

Fixed Point::getX() const {
	return x;
}

Fixed Point::getY() const {
	return y;
}

bool Point::operator==(Point const &rhs) const {
	return (this->getX() == rhs.getX() && this->getY() == rhs.getY());
}

Fixed calculateArea(Point const a, Point const b, Point const c) {
	Fixed area = (a.getX() * (b.getY() - c.getY()) +
				  b.getX() * (c.getY() - a.getY()) +
				  c.getX() * (a.getY() - b.getY())) / 2;
	if (area.toFloat() < 0)
		return Fixed(-area.toFloat());
	return area;
}


bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed area = calculateArea(a, b, c);
	Fixed area1 = calculateArea(point, b, c);
	Fixed area2 = calculateArea(a, point, c);
	Fixed area3 = calculateArea(a, b, point);

	if (point == a || point == b || point == c)
		return false;
	
	if (area == 0 || area2 == 0 || area3 == 0)
		return false;

	if (area == area1 + area2 + area3)
		return true;

	return false;
}