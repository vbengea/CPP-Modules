#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain& rhs);
		Brain& operator=(const Brain& rhs);
		~Brain();

		void setIdea(std::string idea, int index);
		std::string getIdea(int index);

	private:
		std::string ideas[100];
};

#endif // BRAIN_HPP
