#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(const AAnimal& rhs);
		AAnimal& operator=(const AAnimal& rhs);
		virtual ~AAnimal();

		virtual void makeSound() const = 0;

		std::string getType() const;
		void setType(std::string type);

	protected:
		std::string _type;
};

#endif // ANIMAL_HPP
