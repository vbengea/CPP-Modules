#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "\n=== Testing ScavTrap Constructors ===\n" << std::endl;
	
	// Test different constructors
	ScavTrap scav1("Guardian");
	ScavTrap scav2(scav1);  // Copy constructor
	ScavTrap scav3;         // Default constructor
	scav3 = scav1;          // Assignment operator
	
	std::cout << "\n=== Testing Base Stats ===\n" << std::endl;
	std::cout << "ScavTrap " << scav1.getName() << " stats:" << std::endl;
	std::cout << "HP: " << scav1.getHitpoints() << std::endl;
	std::cout << "Energy: " << scav1.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << scav1.getAttackDamage() << std::endl;
	
	std::cout << "\n=== Testing Combat Functions ===\n" << std::endl;
	
	// Test attack and damage
	scav1.attack("Enemy Robot");
	scav2.takeDamage(30);
	scav2.beRepaired(15);
	
	std::cout << "\n=== Testing Guard Gate Feature ===\n" << std::endl;
	
	// Test guard mode
	scav1.guardGate();
	scav1.guardGate(); // Should print "already in guard mode"
	
	std::cout << "\n=== Testing Energy Point Depletion ===\n" << std::endl;
	
	// Test energy point depletion
	for (int i = 0; i < 51; i++) {
		scav3.attack("Training Dummy");
	}
	
	std::cout << "\n=== Testing Fatal Damage ===\n" << std::endl;
	
	// Test taking fatal damage
	scav2.takeDamage(200);  // Should deplete all HP
	scav2.attack("Target"); // Should fail - no HP
	scav2.beRepaired(50);   // Should fail - no HP
	scav2.guardGate();      // Should still work even with 0 HP
	
	std::cout << "\n=== Testing Mixed ClapTrap/ScavTrap Interaction ===\n" << std::endl;
	
	// Test interaction between ClapTrap and ScavTrap
	ClapTrap clap("Regular Bot");
	clap.attack(scav1.getName());
	scav1.takeDamage(clap.getAttackDamage());
	
	std::cout << "\n=== End of Tests ===\n" << std::endl;
	
	return 0;
}