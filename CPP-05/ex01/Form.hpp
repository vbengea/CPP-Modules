#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
class Bureaucrat;

class Form
{
	public:
		Form(const Form& rhs);
		Form& operator=(const Form& rhs);
		Form(std::string name, int gradeSign, int gradeExec);
		~Form();

		class GradeTooHighExeption : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowExeption : public std::exception
		{
			public:
				const char* what() const throw();
		};

		const std::string& getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExec() const;

		void beSigned(const Bureaucrat& bureaucrat);

	private:
		Form();
		const std::string name;
		bool isSigned;
		const int gradeSign;
		const int gradeExec;

};

std::ostream& operator<<(std::ostream& os, const Form& rhs);

#endif // FORM_HPP
