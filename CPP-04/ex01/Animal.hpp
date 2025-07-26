#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal& rhs);
		Animal& operator=(const Animal& rhs);
		virtual ~Animal();

		virtual void makeSound() const;

		std::string getType() const;
		void setType(std::string type);

	protected:
		std::string _type;
};

#endif // ANIMAL_HPP
