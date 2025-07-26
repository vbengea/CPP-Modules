#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& rhs);
		ScavTrap& operator=(const ScavTrap& rhs);
		~ScavTrap();


		void attack(const std::string& target);
		void guardGate();

	protected:
		unsigned int getInitialHitPoints() const;
		unsigned int getInitialEnergyPoints() const;
		unsigned int getInitialAttackDamage() const;
		

	private:
		bool _guardMode;
};

#endif // SCAVTRAP_HPP
