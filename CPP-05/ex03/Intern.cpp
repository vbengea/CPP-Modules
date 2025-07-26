#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {

}

Intern::Intern(const Intern& rhs) {
	(void)rhs;
}

Intern& Intern::operator=(const Intern& rhs) {
	if (this != &rhs) {
		
	}
	return *this;
}

Intern::~Intern() {
	
}

AForm* Intern::createShrubberyForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target) {
	const std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*formCreators[3])(std::string) = {
		&createShrubberyForm,
		&createRobotomyForm,
		&createPresidentialForm
	};

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i](target);
		}
	}

	std::cerr << "Intern can't create form: " << formName << std::endl;

	return NULL;
}