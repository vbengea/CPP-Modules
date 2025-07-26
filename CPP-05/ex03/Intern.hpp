#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& rhs);
		Intern& operator=(const Intern& rhs);
		~Intern();

		AForm* makeForm(std::string formName, std::string target);

		static AForm* createShrubberyForm(std::string target);
		static AForm* createRobotomyForm(std::string target);
		static AForm* createPresidentialForm(std::string target);

	private:
		
};

#endif // INTERN_HPP
