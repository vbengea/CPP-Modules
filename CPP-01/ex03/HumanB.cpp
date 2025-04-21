#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name) {
	// Constructor implementation
	// std::cout << "HumanB created with weapon type: " << gun->getType() << std::endl;
}

HumanB::~HumanB() {
	// Destructor implementation
	// std::cout << "HumanB destroyed." << std::endl;
}

void HumanB::attack() const {
	if (!gun) {
		std::cout << getName() << " has no weapon to attack with!" << std::endl;
		return;
	}
	std::cout << getName() << " attacks with their " << gun->getType() << std::endl;
}


std::string HumanB::getName() const {
	return this->name;
}

void HumanB::setName(std::string name) {
	this->name = name;
}

void HumanB::setWeapon(Weapon& gun){
	this->gun = &gun;
}