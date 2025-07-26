#ifndef AForm_HPP
# define AForm_HPP

#include <iostream>
class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const AForm& rhs);
		AForm& operator=(const AForm& rhs);
		AForm(std::string name, int gradeSign, int gradeExec);
		~AForm();

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

		virtual void execute(const Bureaucrat& executor) const = 0;

	private:
		const std::string name;
		bool isSigned;
		const int gradeSign;
		const int gradeExec;

};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);

#endif // AForm_HPP
