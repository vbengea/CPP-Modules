#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guardMode = false;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guardMode = false;
	std::cout << "ScavTrap constructor called with name: " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& rhs) : ClapTrap(rhs) {
	_guardMode = rhs._guardMode;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
		_guardMode = rhs._guardMode;
		std::cout << "ScavTrap assignment operator called" << std::endl;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	} else {
		std::cout << "ScavTrap " << _name << " is out of energy or hit points!" << std::endl;
	}
}


void ScavTrap::guardGate() {
	if (_guardMode) {
		std::cout << "ScavTrap " << _name << " is already in guard mode!" << std::endl;
	} else {
		_guardMode = true;
		std::cout << "ScavTrap " << _name << " is now in guard mode!" << std::endl;
	}
}
