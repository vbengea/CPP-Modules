#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n=== CONSTRUCTORS TESTS ===\n" << std::endl;
	
	FragTrap frag1("Warrior");
	FragTrap frag2(frag1);      // Copy constructor test
	FragTrap frag3;             // Default constructor test
	frag3 = frag1;              // Assignment operator test

	std::cout << "\n=== STATS VERIFICATION ===\n" << std::endl;
	
	std::cout << "FragTrap " << frag1.getName() << " stats:" << std::endl;
	std::cout << "HP: " << frag1.getHitpoints() << std::endl;
	std::cout << "Energy: " << frag1.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << frag1.getAttackDamage() << std::endl;

	std::cout << "\n=== COMBAT FUNCTIONALITY ===\n" << std::endl;
	
	// Test basic combat functions
	frag1.attack("Enemy");
	frag2.takeDamage(50);
	frag2.beRepaired(20);

	std::cout << "\n=== HIGH FIVE REQUESTS ===\n" << std::endl;
	
	frag1.highFivesGuys();
	frag2.highFivesGuys();

	std::cout << "\n=== ENERGY DEPLETION TEST ===\n" << std::endl;
	
	// Should deplete all energy points (100 attacks)
	for (int i = 0; i < 101; i++) {
		std::cout << "Attack " << i + 1 << ": ";
		frag3.attack("Training Dummy");
	}

	std::cout << "\n=== DEATH SIMULATION ===\n" << std::endl;
	
	// Test behavior when HP reaches 0
	frag2.takeDamage(200);      // Should deplete all HP
	frag2.attack("Target");      // Should fail - no HP
	frag2.beRepaired(50);       // Should fail - no HP
	frag2.highFivesGuys();      // Should still work even with 0 HP

	std::cout << "\n=== INHERITANCE TEST ===\n" << std::endl;
	
	// Test ClapTrap and FragTrap interaction
	ClapTrap clap("Base Robot");
	clap.attack(frag1.getName());
	frag1.takeDamage(clap.getAttackDamage());

	std::cout << "\n=== END OF TESTS ===\n" << std::endl;

	return 0;
}