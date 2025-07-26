#include "AForm.hpp"
#include "Bureaucrat.hpp"

// AForm::AForm() {
	
// }

AForm::AForm(std::string name, int gradeSign, int gradeExec) :
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


AForm::AForm(const AForm& rhs) :
	name(rhs.name),
	isSigned(rhs.isSigned),
	gradeSign(rhs.gradeSign),
	gradeExec(rhs.gradeExec) {
	
}

AForm& AForm::operator=(const AForm& rhs) {
	if (this != &rhs) {
		this->isSigned = rhs.isSigned;
	}
	return *this;
}

AForm::~AForm() {
	
}


const char* AForm::GradeTooHighExeption::what() const throw() {
	return "Grade too high!";
}

const char* AForm::GradeTooLowExeption::what() const throw() {
	return "Grade too low!";
}


const std::string& AForm::getName() const {
	return this->name;
}

bool AForm::getSigned() const {
	return this->isSigned;
}

int AForm::getGradeSign() const {
	return this->gradeSign;
}

int AForm::getGradeExec() const {
	return this->gradeExec;
}


void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->getGradeSign()) {
		this->isSigned = true;
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
	} else {
		std::cout << bureaucrat.getName() << " couldn't sign AForm " << this->getName() << " because it's grade is " << bureaucrat.getGrade() << " and the AForm requires " << this->getGradeSign() << std::endl;
		throw GradeTooLowExeption();
	}
}


std::ostream& operator<<(std::ostream& os, const AForm& rhs) {
	os << rhs.getName() << ", is signed: ";
	if (rhs.getSigned())
		os << "true\n";
	else
		os << "false\n";
	os << "Grade required to sign it: " << rhs.getGradeSign();
	os << "\nGrade required to execute it: " << rhs.getGradeExec();
	return os;
}

