#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
		~ShrubberyCreationForm();

		void execute(const Bureaucrat& executor) const;

		const std::string& getTarget() const;

	private:
		ShrubberyCreationForm();
		std::string target;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& rhs);

#endif // SHRUBBERYCREATIONFORM_HPP
