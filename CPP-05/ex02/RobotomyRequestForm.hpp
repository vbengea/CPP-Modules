#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& rhs);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
		~RobotomyRequestForm();

		void execute(const Bureaucrat& executor) const;
		const std::string& getTarget() const;

	private:
		RobotomyRequestForm();
		std::string target;
};

#endif // ROBOTOMYREQUESTFORM_HPP
