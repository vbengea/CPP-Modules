#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat
{
	public:
		Bureaucrat(const Bureaucrat& rhs);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();

		const std::string& getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		void signForm(AForm& AForm);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		void executeForm(const AForm& form) const;

	private:
		Bureaucrat();
		
		const std::string name;
		int grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);



#endif // BUREAUCRAT_HPP
