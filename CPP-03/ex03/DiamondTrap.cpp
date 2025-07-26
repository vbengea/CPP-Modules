#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"),
							FragTrap("default_clap_name"),
							ScavTrap("default_clap_name"),
							_name("default")
{
	this->_hitPoints = FragTrap::getInitialHitPoints();
	this->_energyPoints = ScavTrap::getInitialEnergyPoints();
	this->_attackDamage = FragTrap::getInitialAttackDamage();
	std::cout << "DiamondTrap constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
											FragTrap(name),
											ScavTrap(name),
											_name(name)
{
	this->_hitPoints = FragTrap::getInitialHitPoints();
	this->_energyPoints = ScavTrap::getInitialEnergyPoints();
	this->_attackDamage = FragTrap::getInitialAttackDamage();
	std::cout << "DiamondTrap constructor called with name: " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs) :
	ClapTrap(rhs), FragTrap(rhs), ScavTrap(rhs)
{
	_name = rhs._name;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
		_name = rhs._name;
		std::cout << "DiamondTrap assignment operator called" << std::endl;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void) {
	std::cout << "I am DiamondTrap " << this->_name
				<< ", ClapTrap name: " << ClapTrap::_name << std::endl;
}