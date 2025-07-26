#include "Bureaucrat.hpp"

// Bureaucrat::Bureaucrat() {
	
// }

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) 
	: name(rhs.name), grade(rhs.grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	if (this != &rhs) {
		// The name is constant and cannot be assigned, so only grade is updated
		this->grade = rhs.grade;
	}
	return *this;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) :
	name(name), grade(grade) {
	if (this->grade < 1)
		throw GradeTooHighException();
	if (this->grade > 150)
		throw GradeTooLowException();
	}

Bureaucrat::~Bureaucrat() {
	
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

void Bureaucrat::incrementGrade() {
	if (this->grade <= 1)
		throw GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->grade >= 150)
		throw GradeTooLowException();
	this->grade++;
}

const std::string& Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::signForm(AForm& AForm) {
	AForm.beSigned(*this);
}

void Bureaucrat::executeForm(const AForm& form) const {
	try {
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << this->name << " couldn't execute " << form.getName() << " because: " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs) {
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return os;
}