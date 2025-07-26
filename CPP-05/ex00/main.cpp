#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat b("Alice", 0); // too high -> throw
	}  catch (const std::exception& e){
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Bob", 220); // too low -> throw
	}  catch (const std::exception& e){
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Charlie", 50); // valid
		std::cout << "Charlie created successfully" << std::endl;
	}  catch (const std::exception& e){
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Smith", 2); // valid
		std::cout << b.getGrade() << std::endl;
		b.incrementGrade(); // will be 1
		std::cout << b.getGrade() << std::endl;
		b.incrementGrade(); // throw
		std::cout << "Smith created successfully" << std::endl;
	}  catch (const std::exception& e){
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Wil", 148); // valid
		std::cout << b << std::endl;
		b.decrementGrade(); // will be 149
		std::cout << b << std::endl;
		b.decrementGrade(); // will be 150
		std::cout << b << std::endl;
		b.decrementGrade(); // throw
		std::cout << "Smith created successfully" << std::endl;
	}  catch (const std::exception& e){
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}