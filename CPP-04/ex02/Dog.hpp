#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		Dog(const Dog& rhs);
		Dog& operator=(const Dog& rhs);
		~Dog();

		void makeSound() const;

		Brain* getBrain() const;

	private:
		Brain* brain;
};

#endif // DOG_HPP
