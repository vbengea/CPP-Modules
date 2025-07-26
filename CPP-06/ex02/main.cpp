#include "Base.hpp"
#include <iostream>

Base* generate();
void identify(Base* p);
void identify(Base& p);

int main() {
	Base* ptr = generate();

	std::cout << "identify(Base*): ";
	identify(ptr);

	std::cout << "identify(Base&): ";
	identify(*ptr);

	delete ptr;
	return 0;
}
