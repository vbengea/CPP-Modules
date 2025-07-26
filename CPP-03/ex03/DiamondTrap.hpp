#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& rhs);
		DiamondTrap& operator=(const DiamondTrap& rhs);
		~DiamondTrap();

		void whoAmI(void);

	private:
		std::string _name;
};

#endif // DIAMONDTRAP_HPP
