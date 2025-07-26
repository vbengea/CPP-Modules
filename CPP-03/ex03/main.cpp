#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n=== CONSTRUCTORS TESTS ===\n" << std::endl;
	
	DiamondTrap d1("Diamond");
	DiamondTrap d2(d1);         // Copy constructor test
	DiamondTrap d3;             // Default constructor test
	d3 = d1;                    // Assignment operator test

	std::cout << "\n=== INHERITED STATS VERIFICATION ===\n" << std::endl;
	
	// Should show FragTrap HP (100), ScavTrap Energy (50), FragTrap Attack (30)
	std::cout << "DiamondTrap " << d1.getName() << " stats:" << std::endl;
	std::cout << "HP: " << d1.getHitpoints() << " (should be 100)" << std::endl;
	std::cout << "Energy: " << d1.getEnergyPoints() << " (should be 50)" << std::endl;
	std::cout << "Attack Damage: " << d1.getAttackDamage() << " (should be 30)" << std::endl;

	std::cout << "\n=== INHERITED FUNCTIONS TEST ===\n" << std::endl;
	
	// Test ScavTrap inherited functions
	d1.guardGate();
	d1.attack("Enemy");

	// Test FragTrap inherited functions
	d1.highFivesGuys();

	// Test DiamondTrap specific function
	std::cout << "\n=== WHO AM I TEST ===\n" << std::endl;
	d1.whoAmI();
	d2.whoAmI();
	d3.whoAmI();

	std::cout << "\n=== ENERGY DEPLETION TEST ===\n" << std::endl;
	
	// Should deplete all energy points (50 attacks)
	for (int i = 0; i < 51; i++) {
		if (i % 10 == 0) // Print only every 10th attack to keep output clean
			std::cout << "Attack " << i + 1 << ": ";
		d3.attack("Training Dummy");
		if (i % 10 == 0)
			std::cout << "Energy left: " << d3.getEnergyPoints() << std::endl;
	}

	std::cout << "\n=== DAMAGE AND REPAIR TEST ===\n" << std::endl;
	
	d1.takeDamage(50);
	std::cout << "HP after damage: " << d1.getHitpoints() << std::endl;
	d1.beRepaired(20);
	std::cout << "HP after repair: " << d1.getHitpoints() << std::endl;

	std::cout << "\n=== DEATH TEST ===\n" << std::endl;
	
	d2.takeDamage(200);         // Should deplete all HP
	d2.attack("Target");        // Should fail - no HP
	d2.beRepaired(50);         // Should fail - no HP
	d2.guardGate();            // Should still work
	d2.highFivesGuys();        // Should still work
	d2.whoAmI();               // Should still work

	std::cout << "\n=== END OF TESTS ===\n" << std::endl;

	return 0;
}