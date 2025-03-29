#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(const std::string& name, const Weapon& gun); // Constructor
		~HumanA(); // Destructor

		std::string getName() const;
		void setName(std::string name);
		void attack() const;

	private:
		// Add member variables here

	const Weapon& gun;
	std::string name;
};

#endif // HUMANA_HPP
