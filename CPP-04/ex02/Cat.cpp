#include "Cat.hpp"

Cat::Cat() : AAnimal() {
	_type = "Cat";
	brain = new Brain();
	std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& rhs) : AAnimal(rhs) {
	this->_type = rhs._type;
	this->brain = new Brain(*rhs.brain);
	std::cout << "Copy Cat constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
	if (this != &rhs) {
		AAnimal::operator=(rhs);
		this->_type = rhs._type;

		delete brain;
		brain = new Brain(*rhs.brain);
		std::cout << "Assigment Dog constructor called" << std::endl; 
	}
	return *this;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Destructor Cat called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}


Brain* Cat::getBrain() const {return brain;}