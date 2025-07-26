#include "Form.hpp"
#include "Bureaucrat.hpp"

// Form::Form() {
	
// }

Form::Form(std::string name, int gradeSign, int gradeExec) :
	name(name),
	isSigned(false),
	gradeSign(gradeSign),
	gradeExec(gradeExec) {
	if (gradeSign < 1)
		throw GradeTooHighExeption();
	if (gradeSign > 150)
		throw GradeTooLowExeption();
	if (gradeExec < 1)
		throw GradeTooHighExeption();
	if (gradeExec > 150)
		throw GradeTooLowExeption();
}


Form::Form(const Form& rhs) :
	name(rhs.name),
	isSigned(rhs.isSigned),
	gradeSign(rhs.gradeSign),
	gradeExec(rhs.gradeExec) {
	
}

Form& Form::operator=(const Form& rhs) {
	if (this != &rhs) {
		this->isSigned = rhs.isSigned;
	}
	return *this;
}

Form::~Form() {
	
}


const char* Form::GradeTooHighExeption::what() const throw() {
	return "Grade too high!";
}

const char* Form::GradeTooLowExeption::what() const throw() {
	return "Grade too low!";
}


const std::string& Form::getName() const {
	return this->name;
}

bool Form::getSigned() const {
	return this->isSigned;
}

int Form::getGradeSign() const {
	return this->gradeSign;
}

int Form::getGradeExec() const {
	return this->gradeExec;
}


void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->getGradeSign()) {
		this->isSigned = true;
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
	} else {
		std::cout << bureaucrat.getName() << " couldn't sign form " << this->getName() << " because it's grade is " << bureaucrat.getGrade() << " and the form requires " << this->getGradeSign() << std::endl;
		throw GradeTooLowExeption();
	}
}


std::ostream& operator<<(std::ostream& os, const Form& rhs) {
	os << rhs.getName() << ", is signed: ";
	if (rhs.getSigned())
		os << "true\n";
	else
		os << "false\n";
	os << "Grade required to sign it: " << rhs.getGradeSign();
	os << "\nGrade required to execute it: " << rhs.getGradeExec();
	return os;
}

