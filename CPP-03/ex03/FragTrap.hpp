#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& rhs);
		FragTrap& operator=(const FragTrap& rhs);
		~FragTrap();

		void highFivesGuys(void);

	protected:
		unsigned int getInitialHitPoints() const;
		unsigned int getInitialEnergyPoints() const;
		unsigned int getInitialAttackDamage() const;

};

#endif // FRAGTRAP_HPP
