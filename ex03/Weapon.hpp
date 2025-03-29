#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
		Weapon(const std::string& type); // Constructor
		~Weapon(); // Destructor

		const std::string& getType() const;
		void setType(std::string type);

	private:
		// Add member variables here
		std::string type; 
};

#endif // WEAPON_HPP
