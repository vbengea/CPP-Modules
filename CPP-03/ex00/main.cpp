#include "ClapTrap.hpp"

int main(void)
{
	// Test default construction
	ClapTrap bot1("BOT-1");
	ClapTrap bot2("BOT-2");
	
	// Test copy construction
	ClapTrap bot3(bot1);
	
	// Test assignment operator
	ClapTrap bot4("Temporary");
	bot4 = bot2;
	
	// Display initial stats
	std::cout << "\nInitial stats for " << bot1.getName() << ":" << std::endl;
	std::cout << "HP: " << bot1.getHitpoints() << std::endl;
	std::cout << "Energy: " << bot1.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << bot1.getAttackDamage() << std::endl;
	
	// Test attack and damage
	std::cout << "\nTesting attack and damage:" << std::endl;
	bot1.setAttackDamage(3);
	bot1.attack(bot2.getName());
	bot2.takeDamage(3);
	
	// Test repair
	std::cout << "\nTesting repair:" << std::endl;
	bot2.beRepaired(2);
	
	// Test energy point depletion
	std::cout << "\nTesting energy point depletion:" << std::endl;
	for (int i = 0; i < 11; i++) {
		bot1.attack("Target");
	}
	
	// Test taking fatal damage
	std::cout << "\nTesting fatal damage:" << std::endl;
	bot2.takeDamage(20);
	bot2.attack("Target"); // Should fail due to no HP
	bot2.beRepaired(5);   // Should fail due to no HP
	
	return 0;
}