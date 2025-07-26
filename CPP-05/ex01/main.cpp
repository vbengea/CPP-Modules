#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Form a("Test", 5, 6); // valid
		std::cout << a << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Execption: " << e.what() << std::endl;
	}

	try {
		Form a("Test1", 0, 6); // invalid gradeSign
		std::cout << a << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Execption: " << e.what() << std::endl;
	}

	try {
		Form a("Test2", 5, 151); // invalid gradeExec
		std::cout << a << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Execption: " << e.what() << std::endl;
	}

	try {
		Form a("Test3", -3, 200); // both invalid
		std::cout << a << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Execption: " << e.what() << std::endl;
	}


	try {
		Form a("Test", 10, 20); // valid
		std::cout << a << std::endl;
		Bureaucrat b("John", 11); // valid
		std::cout << b << std::endl;

		a.beSigned(b); // attempt to sign the form with an invalid grade
		b.incrementGrade(); // now the grade should be 10;
		// a.beSigned(b); // now it should work since the grade is valid
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Form a("Test", 10, 20); // valid
		std::cout << a << std::endl;
		Bureaucrat b("John", 11); // valid
		std::cout << b << std::endl;

		// a.beSigned(b); // attempt to sign the form with an invalid grade
		b.incrementGrade(); // now the grade should be 10;
		a.beSigned(b); // now it should work since the grade is valid
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

