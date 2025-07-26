#include "Dog.hpp"

Dog::Dog() : Animal() {
	_type = "Dog";
	brain = new Brain();
	std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal(rhs){
	this->_type = rhs._type;
	this->brain = new Brain(*rhs.brain);
	std::cout << "Copy Dog constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
	if (this != &rhs) {
		Animal::operator=(rhs);
		this->_type = rhs._type;

		delete brain;
		brain = new Brain(*rhs.brain);
		std::cout << "Assignment Dog constructor called" << std::endl;
	}
	return *this;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Destructor Dog called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}


Brain* Dog::getBrain() const {return brain;}