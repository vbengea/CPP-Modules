#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, const Weapon& gun) : gun(gun), name(name) {
	// Constructor implementation
	// std::cout << "HumanA created with weapon type: " << gun.getType() << std::endl;
}

HumanA::~HumanA() {
	// Destructor implementation
	// std::cout << "HumanA destroyed." << std::endl;
}

void HumanA::attack() const {
	std::cout << getName() << " attacks with their " << gun.getType() << std::endl;
}


std::string HumanA::getName() const {
	return this->name;
}

void HumanA::setName(std::string name) {
	this->name = name;
}