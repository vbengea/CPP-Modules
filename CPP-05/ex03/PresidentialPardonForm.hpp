#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& rhs);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
		~PresidentialPardonForm();

		void execute(const Bureaucrat& executor) const;
		const std::string& getTarget() const;
	private:
		PresidentialPardonForm();
		std::string target;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& rhs);

#endif // PRESIDENTIALPARDONFORM_HPP
