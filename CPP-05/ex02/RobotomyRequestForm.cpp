#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

// RobotomyRequestForm::RobotomyRequestForm() {
	
// }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs)
	: AForm(rhs), target(rhs.target) {	
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
		this->target = rhs.target;
	}
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), target(target) {
	
}

const std::string& RobotomyRequestForm::getTarget() const {
	return this->target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (!this->getSigned())
		throw AForm::GradeTooLowExeption();
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowExeption();

	std::cout << "* Brzzzzzzzzzzzzzzzzzzz *" << std::endl;

	std::srand(static_cast<unsigned int>(std::time(NULL)));

	if (std::rand() % 2) {
		std::cout << "The robotomy on " << this->target << " has been successful!" << std::endl;
	} else {
		std::cout << "The robotomy on " << this->target << " has failed!" << std::endl;
	}
}

RobotomyRequestForm::~RobotomyRequestForm() {
	
}
