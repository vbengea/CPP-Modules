#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type) {
	// Constructor implementation
	// std::cout << "Weapon created." << std::endl;
}

Weapon::~Weapon() {
	// Destructor implementation
	// std::cout << "Weapon destroyed." << std::endl;
}

const std::string& Weapon::getType() const {
	return this->type;
}

void Weapon::setType(std::string type) {
	this->type = type;
}