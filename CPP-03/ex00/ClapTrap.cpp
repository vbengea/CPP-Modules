#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default constructor with name called." << std::endl;
}

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& rhs) : _name(rhs._name), _hitPoints(rhs._hitPoints), _energyPoints(rhs._energyPoints), _attackDamage(rhs._attackDamage) {
	std::cout << "Copy constructor called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	if (this != &rhs) {
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
	std::cout << "Assignemnt operator called." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called." << std::endl;
}

void ClapTrap::setName(const std::string& name) {
	this->_name = name;
}

void ClapTrap::setHitpoints(unsigned int hitpoints) {
	this->_hitPoints = hitpoints;
}

void ClapTrap::setEnergyPoints(unsigned int energypoints) {
	this->_energyPoints = energypoints;
}

void ClapTrap::setAttackDamage(unsigned int attackdamage) {
	this->_attackDamage = attackdamage;
}

unsigned int ClapTrap::getHitpoints() const {
	return  this->_hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
	return this->_energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
	return this->_attackDamage;
}

std::string ClapTrap::getName() const {
	return this->_name;
}

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is out of hit points and cannot attack!" << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " is out of energy points and cannot attack!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already out of hitpoints!" << std::endl;
		return;
	}

	if (amount >= _hitPoints) {
		std::cout << "ClapTrap " << _name << " takes " << _hitPoints << " points of damage and is now out of hitpoints!" << std::endl;
		_hitPoints = 0;
	} else {
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
		_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is out of hit points and cannot be repaired!" << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " is out of energy points and cannot be repaired!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points!" << std::endl;
	_hitPoints += amount;
}