#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& rhs);
		Dog& operator=(const Dog& rhs);
		~Dog();

		void makeSound() const;

	private:
		
};

#endif // DOG_HPP
