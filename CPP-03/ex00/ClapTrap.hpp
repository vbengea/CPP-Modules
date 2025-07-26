#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& rhs);
		ClapTrap& operator=(const ClapTrap& rhs);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		// Getters
		std::string getName() const;
		unsigned int getHitpoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getAttackDamage() const;

		// Setters
		void setName(const std::string& name);
		void setHitpoints(unsigned int hitpoints);
		void setEnergyPoints(unsigned int energypoints);
		void setAttackDamage(unsigned int attackdamage);

	private:
		// Add member variables here
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
};

#endif // CLAPTRAP_HPP
