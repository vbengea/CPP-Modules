#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// PresidentialPardonForm::PresidentialPardonForm() {
	
// }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs) 
	: AForm(rhs), target(rhs.target) {
	
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
		this->target = rhs.target;
	}
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5), target(target) {

}

PresidentialPardonForm::~PresidentialPardonForm() {
	
}

const std::string& PresidentialPardonForm::getTarget() const {
	return this->target;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (!this->getSigned())
		throw AForm::GradeTooLowExeption();
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowExeption();

	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}


std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& rhs) {
	os << "PresidentialPardonForm: " << rhs.getName() << ", "
		<< "isSigned: " << (rhs.getSigned() ? "true" : "false") << ", "
		<< "gradeSign: " << rhs.getGradeSign() << ", "
		<< "gradeExec: " << rhs.getGradeExec() << ", "
		<< "target: " << rhs.getTarget();
	return os;
}