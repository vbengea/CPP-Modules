#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor with name " << _name << " called." << std::endl;
}

// Just call parent copy constructor
FragTrap::FragTrap(const FragTrap& rhs) : ClapTrap(rhs) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

// Just call parent assignment operator
FragTrap& FragTrap::operator=(const FragTrap& rhs) {
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
		std::cout << "FragTrap assignment operator called." << std::endl;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called." << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << ClapTrap::_name << " requests a positive high five!" << std::endl;
}