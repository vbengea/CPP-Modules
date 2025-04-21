#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(const std::string& name); // Constructor
		~HumanB(); // Destructor

		std::string getName() const;
		void setName(std::string name);
		void attack() const;
		void setWeapon(Weapon& gun);

	private:
		// Add member variables here

	Weapon* gun;
	std::string name;
};

#endif // HUMANA_HPP
