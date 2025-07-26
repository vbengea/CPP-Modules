#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& rhs);
		WrongAnimal& operator=(const WrongAnimal& rhs);
		virtual ~WrongAnimal();

		std::string getType() const;
		void setType(std::string type);

		void makeSound() const; // Removed virtual keyword

	protected:
		std::string _type;
};

#endif // WRONGANIMAL_HPP
