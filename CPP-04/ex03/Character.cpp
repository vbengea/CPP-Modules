#include "Character.hpp"

// Character::Character() {
	
// }

Character::Character(std::string name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		this->_materia[i] = NULL;
	}
}

Character::Character(const Character& rhs) {
	for (int i = 0; i < 4; i++) {
		if (rhs._materia[i]) {
			this->_materia[i] = rhs._materia[i]->clone();
		} else {
			this->_materia[i] = NULL;
		}
	}
	this->_name = rhs._name;
	// std::cout << "Copy constructor Character called" << std::endl;
}

Character& Character::operator=(const Character& rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 4; i++) {
			if (this->_materia[i]) {
				delete this->_materia[i];
				this->_materia[i] = NULL;
			}
			if (rhs._materia[i]) {
				this->_materia[i] = rhs._materia[i]->clone();
			} else {
				this->_materia[i] = NULL;
			}
		}
		this->_name = rhs._name;
		// std::cout << "Copy assignment operator Character called" << std::endl;
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i]) {
			delete this->_materia[i];
			this->_materia[i] = NULL;
		}
	}
	// std::cout << "Destructor Character called" << std::endl;
}


std::string const & Character::getName() const {
	return this->_name;
}

AMateria* Character::getMateria(int idx) const {
	if (idx >= 0 && idx < 4) {
		return this->_materia[idx];
	}
	return NULL;
}

void Character::equip(AMateria* m) {
	if (m == NULL) {
		std::cout << "Materia is NULL" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] == NULL) {
			this->_materia[i] = m;
			// std::cout << "Materia " << m->getType() << " equipped" << std::endl;
			return;
		}
	}
	std::cout << "Inventory full, cannot equip more materias" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3) {
		std::cout << "Index out of range" << std::endl;
		return;
	}
	if (this->_materia[idx] == NULL) {
		// std::cout << "Materia is NULL" << std::endl;
		return;
	}
	// std::cout << "Materia " << this->_materia[idx]->getType() << " unequipped" << std::endl;
	this->_materia[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3) {
		std::cout << "Index out of range" << std::endl;
		return;
	}
	if (this->_materia[idx] == NULL) {
		// std::cout << "Materia is NULL" << std::endl;
		return;
	}
	// std::cout << "Materia " << this->_materia[idx]->getType() << " used" << std::endl;
	this->_materia[idx]->use(target);
}