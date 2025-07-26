#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	
	std::srand(static_cast<unsigned>(std::time(NULL)));
	
	Span c(10000);

	std::vector<int> test(10000);

	for (int i = 0; i < 10000; i++) {
		test[i] = std::rand();
	}

	c.addMultipleNumbers(test.begin(), test.end());

	try {
		c.addNumber(20); // throw error
	} catch (std::runtime_error &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << c.shortestSpan() << std::endl;
	std::cout << c.longestSpan() << std::endl;

	Span a(1);

	a.addNumber(7);

	try {
		a.addNumber(3); // throw
	} catch (std::runtime_error &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << a.shortestSpan() << std::endl; // throw
	} catch (std::runtime_error &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << a.longestSpan() << std::endl; // throw
	} catch (std::runtime_error &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}


// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }
