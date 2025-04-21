#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	Zombie* zombie = new Zombie();

	zombie->setName(name);
	return (zombie);
}

void randomChump(std::string name) {
	Zombie zombie;

	zombie.setName(name);
	zombie.announce();
}



Zombie::Zombie() {
	// Constructor implementation
	std::cout << "Zombie created" << std::endl;
}

Zombie::~Zombie() {
	// Destructor implementation
	std::cout << "Zombie deleted" << std::endl;
}

void Zombie::setName (std::string name) {
	this->name = name;
}

std::string Zombie::getName(void) const {
	return this->name;
}

void Zombie::announce (void) {
	std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
