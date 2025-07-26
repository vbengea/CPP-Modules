#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"


// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }


void test_basic_functionality() {
	std::cout << "\n=== BASIC FUNCTIONALITY TEST ===\n" << std::endl;
	
	// Create a MateriaSource
	IMateriaSource* src = new MateriaSource();
	
	// Learn materias
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	// Create a character
	ICharacter* me = new Character("me");
	
	// Create materias and equip them
	AMateria* tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	// Create another character
	ICharacter* bob = new Character("bob");
	
	// Use materias on bob
	std::cout << "Using materia 0 (ice):" << std::endl;
	me->use(0, *bob);
	std::cout << "Using materia 1 (cure):" << std::endl;
	me->use(1, *bob);
	
	// Test invalid uses
	std::cout << "\nTesting invalid uses:" << std::endl;
	me->use(2, *bob); // Empty slot
	me->use(-1, *bob); // Invalid index
	me->use(4, *bob); // Invalid index
	
	// Cleanup
	delete bob;
	delete me;
	delete src;
}

void test_unequip() {
	std::cout << "\n=== UNEQUIP TEST ===\n" << std::endl;
	
	// Create character and materias
	Character* me = new Character("me");
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	
	// Equip materias
	me->equip(ice);
	me->equip(cure);
	
	// Use before unequip
	ICharacter* bob = new Character("bob");
	std::cout << "Before unequip:" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	
	// Unequip and verify
	std::cout << "\nUnequipping materia 0 (ice)..." << std::endl;
	me->unequip(0);
	std::cout << "After unequip:" << std::endl;
	me->use(0, *bob); // Should do nothing as it's unequipped
	me->use(1, *bob); // Should still work
	
	// Re-equip the unequipped materia
	std::cout << "\nRe-equipping ice to slot 2..." << std::endl;
	me->equip(ice);
	me->use(0, *bob); // Should do nothing
	me->use(1, *bob); // Should be cure
	me->use(2, *bob); // Should be ice
	
	// Clean up
	delete bob;
	delete me;
	// Don't delete ice since it was re-equipped and will be deleted by the Character destructor
}

void test_copy_constructor() {
	std::cout << "\n=== COPY CONSTRUCTOR TEST ===\n" << std::endl;
	
	// Create and setup original character
	Character* original = new Character("original");
	original->equip(new Ice());
	original->equip(new Cure());
	
	// Create a copy
	Character* copy = new Character(*original);
	
	// Create target
	ICharacter* target = new Character("target");
	
	// Use materias from both
	std::cout << "Original using materias:" << std::endl;
	original->use(0, *target);
	original->use(1, *target);
	
	std::cout << "\nCopy using materias:" << std::endl;
	copy->use(0, *target);
	copy->use(1, *target);
	

	AMateria* tmp = original->getMateria(0); // Store a temp value before unequipping

	// Modify original and show copy is independent
	std::cout << "\nUnequipping from original..." << std::endl;
	original->unequip(0);

	delete tmp; // Clean the original materia
	
	std::cout << "Original after unequip:" << std::endl;
	original->use(0, *target); // Should do nothing
	
	std::cout << "\nCopy after original was modified:" << std::endl;
	copy->use(0, *target); // Should still work

	
	// Clean up
	delete target;
	delete copy;
	delete original;
}

void test_assignment_operator() {
	std::cout << "\n=== ASSIGNMENT OPERATOR TEST ===\n" << std::endl;
	
	// Create two characters
	Character* c1 = new Character("c1");
	c1->equip(new Ice());
	
	Character* c2 = new Character("c2");
	c2->equip(new Cure());
	
	// Target for using materias
	ICharacter* target = new Character("target");
	
	// Before assignment
	std::cout << "Before assignment:" << std::endl;
	std::cout << "c1 name: " << c1->getName() << std::endl;
	c1->use(0, *target);
	
	std::cout << "\nc2 name: " << c2->getName() << std::endl;
	c2->use(0, *target);
	
	// Perform assignment
	std::cout << "\nPerforming assignment c1 = c2" << std::endl;
	*c1 = *c2;
	
	// After assignment
	std::cout << "\nAfter assignment:" << std::endl;
	std::cout << "c1 name: " << c1->getName() << std::endl;
	c1->use(0, *target);
	
	// Clean up
	delete target;
	delete c1;
	delete c2;
}

void test_edge_cases() {
	std::cout << "\n=== EDGE CASES TEST ===\n" << std::endl;
	
	// Test NULL materia
	Character* me = new Character("me");
	std::cout << "Equipping NULL materia:" << std::endl;
	me->equip(NULL);
	
	// Test creating non-existent materia
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	
	std::cout << "\nCreating non-existent materia type:" << std::endl;
	AMateria* tmp = src->createMateria("fire"); // Should return NULL
	if (tmp == NULL)
		std::cout << "Correctly returned NULL for non-existent type" << std::endl;
	else
		std::cout << "ERROR: Should have returned NULL" << std::endl;
	
	// Test full inventory
	std::cout << "\nFilling inventory with 4 materias:" << std::endl;
	me->equip(new Ice());
	me->equip(new Cure());
	me->equip(new Ice());
	me->equip(new Cure());
	
	// Try to equip when full
	std::cout << "Trying to equip when inventory is full:" << std::endl;
	AMateria* extra = new Ice();
	me->equip(extra);
	
	// Don't leak memory
	delete extra;
	delete me;
	delete src;
}

int main() {
	test_basic_functionality();
	test_unequip();
	test_copy_constructor();
	test_assignment_operator();
	test_edge_cases();
	
	std::cout << "\nAll tests completed!" << std::endl;
	return 0;
}