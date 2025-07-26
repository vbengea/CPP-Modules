#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

// int main()
// {
// 	Point a(0.0f, 0.0f);
// 	Point b(4.0f, 0.0f);
// 	Point c(2.0f, 3.0f);
// 	Point point(2.0f, 1.0f);

// 	bool isInside = bsp(a, b, c, point);
// 	std::cout << "Point is " << (isInside ? "inside" : "outside") << " the triangle" << std::endl;

// 	return 0;
// }

/*
//    c
//    /\
//   /  \
//  /    \
// /  P   \
//a--------b

// If P is inside:
// Area(abc) = Area(Pbc) + Area(aPc) + Area(abP)
*/

void test_bsp(void) {
	std::cout << "\n=== BSP TESTS ===" << std::endl;

	// Test 1: Point inside triangle
	{
		Point a(0, 0);
		Point b(4, 0);
		Point c(2, 4);
		Point point(2, 1);
		
		std::cout << "Test 1 - Point inside triangle: ";
		std::cout << (bsp(a, b, c, point) ? "PASS" : "FAIL") << std::endl;
	}

	// Test 2: Point on vertex
	{
		Point a(0, 0);
		Point b(4, 0);
		Point c(2, 4);
		Point point(0, 0);  // Point on vertex A
		
		std::cout << "Test 2 - Point on vertex: ";
		std::cout << (!bsp(a, b, c, point) ? "PASS" : "FAIL") << std::endl;
	}

	// Test 3: Point on edge
	{
		Point a(0, 0);
		Point b(4, 0);
		Point c(2, 4);
		Point point(2, 0);  // Point on bottom edge
		
		std::cout << "Test 3 - Point on edge: ";
		std::cout << (!bsp(a, b, c, point) ? "PASS" : "FAIL") << std::endl;
	}

	// Test 4: Point outside triangle
	{
		Point a(0, 0);
		Point b(4, 0);
		Point c(2, 4);
		Point point(5, 5);
		
		std::cout << "Test 4 - Point outside triangle: ";
		std::cout << (!bsp(a, b, c, point) ? "PASS" : "FAIL") << std::endl;
	}

	// Test 5: Point at center
	{
		Point a(0, 0);
		Point b(3, 0);
		Point c(1.5, 3);
		Point point(1.5, 1);
		
		std::cout << "Test 5 - Point at center: ";
		std::cout << (bsp(a, b, c, point) ? "PASS" : "FAIL") << std::endl;
	}

	// Test 6: Negative coordinates
	{
		Point a(-2, -2);
		Point b(2, -2);
		Point c(0, 2);
		Point point(0, 0);
		
		std::cout << "Test 6 - Negative coordinates: ";
		std::cout << (bsp(a, b, c, point) ? "PASS" : "FAIL") << std::endl;
	}
}

int main(void) {
	test_bsp();
	return 0;
}