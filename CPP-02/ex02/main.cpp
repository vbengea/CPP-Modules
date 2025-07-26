// #include <iostream>
// #include "Fixed.hpp"

// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }


#include "Fixed.hpp"
#include <iostream>
#include <sstream>
#include <cassert>
#include <cmath>

class FixedTest {
private:
	static int testCount;
	static int passCount;

	static void printTestResult(const std::string& testName, bool passed) {
		std::cout << (passed ? "[PASS] " : "[FAIL] ") << testName << std::endl;
		testCount++;
		if (passed) passCount++;
	}

	static bool compareFloat(float a, float b) {
		float epsilon = 0.00390625f; // 1/256 for 8 fractional bits
		return std::fabs(a - b) < epsilon;
	}

public:
	static void testConstructors() {
		// Default constructor
		Fixed a;
		printTestResult("Default constructor initializes to 0", a.toFloat() == 0.0f);

		// Int constructor
		Fixed b(42);
		printTestResult("Int constructor", b.toInt() == 42);

		// Float constructor
		Fixed c(42.42f);
		printTestResult("Float constructor", compareFloat(c.toFloat(), 42.42f));

		// Copy constructor
		Fixed d(b);
		printTestResult("Copy constructor", d.toInt() == b.toInt());
	}

	static void testArithmeticOperators() {
		Fixed a(10);
		Fixed b(5);

		// Addition
		Fixed sum = a + b;
		printTestResult("Addition operator", sum.toInt() == 15);

		// Subtraction
		Fixed diff = a - b;
		printTestResult("Subtraction operator", diff.toInt() == 5);

		// Multiplication
		Fixed prod = a * b;
		printTestResult("Multiplication operator", prod.toInt() == 50);

		// Division
		Fixed div = a / b;
		printTestResult("Division operator", div.toInt() == 2);

		// Division by zero
		Fixed zero(0);
		Fixed divByZero = a / zero;
		printTestResult("Division by zero handling", divByZero.toInt() == 0);
	}

	static void testIncrementDecrement() {
		Fixed a(5);
		
		// Pre-increment
		Fixed b = ++a;
		printTestResult("Pre-increment value", a.toInt() == 6);
		printTestResult("Pre-increment return", b.toInt() == 6);

		// Post-increment
		Fixed c = a++;
		printTestResult("Post-increment original value", c.toInt() == 6);
		printTestResult("Post-increment new value", a.toInt() == 7);

		// Pre-decrement
		Fixed d = --a;
		printTestResult("Pre-decrement value", a.toInt() == 6);
		printTestResult("Pre-decrement return", d.toInt() == 6);

		// Post-decrement
		Fixed e = a--;
		printTestResult("Post-decrement original value", e.toInt() == 6);
		printTestResult("Post-decrement new value", a.toInt() == 5);
	}

	static void testComparisonOperators() {
		Fixed a(10);
		Fixed b(5);
		Fixed c(10);

		printTestResult("Greater than operator", a > b && !(b > a));
		printTestResult("Less than operator", b < a && !(a < b));
		printTestResult("Greater than or equal operator", a >= c && a >= b);
		printTestResult("Less than or equal operator", b <= a && a <= c);
		printTestResult("Equal operator", a == c && !(a == b));
		printTestResult("Not equal operator", a != b && !(a != c));
	}

	static void testMinMax() {
		Fixed a(10);
		Fixed b(5);
		const Fixed c(15);
		const Fixed d(3);

		printTestResult("Min function (non-const)", Fixed::min(a, b).toInt() == 5);
		printTestResult("Max function (non-const)", Fixed::max(a, b).toInt() == 10);
		printTestResult("Min function (const)", Fixed::min(c, d).toInt() == 3);
		printTestResult("Max function (const)", Fixed::max(c, d).toInt() == 15);
	}

	static void testFloatConversion() {
		Fixed a(3.14159f);
		printTestResult("Float conversion precision", compareFloat(a.toFloat(), 3.14159f));

		Fixed b(-42.42f);
		printTestResult("Negative float conversion", compareFloat(b.toFloat(), -42.42f));

		Fixed c(0.0f);
		printTestResult("Zero float conversion", compareFloat(c.toFloat(), 0.0f));
	}


	static void runAllTests() {
		std::cout << "Running Fixed number tests...\n" << std::endl;
		
		testConstructors();
		testArithmeticOperators();
		testIncrementDecrement();
		testComparisonOperators();
		testMinMax();
		testFloatConversion();

		std::cout << "\nTest Summary: " << passCount << "/" << testCount 
				  << " tests passed (" 
				  << (passCount * 100.0f / testCount) << "%)" << std::endl;
	}
};

int FixedTest::testCount = 0;
int FixedTest::passCount = 0;

int main() {
	FixedTest::runAllTests();
	return 0;
}