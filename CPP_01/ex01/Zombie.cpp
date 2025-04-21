#include "Zombie.hpp"

Zombie::Zombie() {
	// Constructor implementation
	std::cout << "Zombie created." << std::endl;
}

Zombie::~Zombie() {
	// Destructor implementation
	std::cout << "Zombie destroyed." << std::endl;
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

Zombie* zombieHorde(int N, std::string name) {
	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}
	return (horde);
}