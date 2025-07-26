#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void printSeparator() {
	std::cout << "\n\n" << std::string(50, '=') << "\n\n";
}

void testShrubberyCreationForm() {
	std::cout << "===== TESTING SHRUBBERY CREATION FORM =====" << std::endl;
	
	// Test with valid bureaucrat who can sign and execute
	try {
		std::cout << "\nTest 1: Valid bureaucrat who can sign and execute" << std::endl;
		Bureaucrat highGrade("Director", 1); // Highest possible grade
		ShrubberyCreationForm shrubberyForm("garden");
		
		std::cout << "Form: " << shrubberyForm.getName() 
				  << ", Sign Grade: " << shrubberyForm.getGradeSign()
				  << ", Exec Grade: " << shrubberyForm.getGradeExec() << std::endl;
		std::cout << "Bureaucrat: " << highGrade << std::endl;
		
		highGrade.signForm(shrubberyForm);
		highGrade.executeForm(shrubberyForm);
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	// Test with bureaucrat who can sign but not execute
	try {
		std::cout << "\nTest 2: Bureaucrat who can sign but not execute" << std::endl;
		Bureaucrat midGrade("Manager", 140); // Can sign (145) but not execute (137)
		ShrubberyCreationForm shrubberyForm("park");
		
		std::cout << "Form: " << shrubberyForm.getName() 
				  << ", Sign Grade: " << shrubberyForm.getGradeSign()
				  << ", Exec Grade: " << shrubberyForm.getGradeExec() << std::endl;
		std::cout << "Bureaucrat: " << midGrade << std::endl;
		
		midGrade.signForm(shrubberyForm);
		midGrade.executeForm(shrubberyForm); // Should fail
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	// Test with bureaucrat who cannot sign or execute
	try {
		std::cout << "\nTest 3: Bureaucrat who cannot sign or execute" << std::endl;
		Bureaucrat lowGrade("Intern", 150); // Lowest possible grade
		ShrubberyCreationForm shrubberyForm("backyard");
		
		std::cout << "Form: " << shrubberyForm.getName() 
				  << ", Sign Grade: " << shrubberyForm.getGradeSign()
				  << ", Exec Grade: " << shrubberyForm.getGradeExec() << std::endl;
		std::cout << "Bureaucrat: " << lowGrade << std::endl;
		
		lowGrade.signForm(shrubberyForm); // Should fail
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	// Test executing unsigned form
	try {
		std::cout << "\nTest 4: Executing unsigned form" << std::endl;
		Bureaucrat executive("CEO", 1);
		ShrubberyCreationForm shrubberyForm("office");
		
		std::cout << "Form: " << shrubberyForm.getName() 
				  << " (unsigned), Bureaucrat: " << executive << std::endl;
		
		// Try to execute without signing first
		executive.executeForm(shrubberyForm); // Should fail
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testRobotomyRequestForm() {
	std::cout << "===== TESTING ROBOTOMY REQUEST FORM =====" << std::endl;
	
	// Test with valid bureaucrat
	try {
		std::cout << "\nTest 1: Valid bureaucrat who can sign and execute" << std::endl;
		Bureaucrat director("Director", 1);
		RobotomyRequestForm robotomyForm("Bender");
		
		std::cout << "Form: " << robotomyForm.getName() 
				  << ", Sign Grade: " << robotomyForm.getGradeSign()
				  << ", Exec Grade: " << robotomyForm.getGradeExec() << std::endl;
		std::cout << "Bureaucrat: " << director << std::endl;
		
		director.signForm(robotomyForm);
		director.executeForm(robotomyForm);
		
		// Test multiple executions to see the 50% success rate
		std::cout << "\nExecuting multiple times to demonstrate 50% success rate:" << std::endl;
		for (int i = 0; i < 5; i++) {
			director.executeForm(robotomyForm);
		}
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	// Test with bureaucrat who can sign but not execute
	try {
		std::cout << "\nTest 2: Bureaucrat who can sign but not execute" << std::endl;
		Bureaucrat assistant("Assistant", 65); // Can sign (72) but not execute (45)
		RobotomyRequestForm robotomyForm("C-3PO");
		
		std::cout << "Form: " << robotomyForm.getName() 
				  << ", Sign Grade: " << robotomyForm.getGradeSign()
				  << ", Exec Grade: " << robotomyForm.getGradeExec() << std::endl;
		std::cout << "Bureaucrat: " << assistant << std::endl;
		
		assistant.signForm(robotomyForm);
		assistant.executeForm(robotomyForm); // Should fail
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testPresidentialPardonForm() {
	std::cout << "===== TESTING PRESIDENTIAL PARDON FORM =====" << std::endl;
	
	// Test with valid bureaucrat
	try {
		std::cout << "\nTest 1: Valid bureaucrat who can sign and execute" << std::endl;
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardonForm("Arthur Dent");
		
		std::cout << "Form: " << pardonForm.getName() 
				  << ", Sign Grade: " << pardonForm.getGradeSign()
				  << ", Exec Grade: " << pardonForm.getGradeExec() << std::endl;
		std::cout << "Bureaucrat: " << president << std::endl;
		
		president.signForm(pardonForm);
		president.executeForm(pardonForm);
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	// Test with bureaucrat who can sign but not execute
	try {
		std::cout << "\nTest 2: Bureaucrat who can sign but not execute" << std::endl;
		Bureaucrat vicePresident("Vice President", 10); // Can sign (25) but not execute (5)
		PresidentialPardonForm pardonForm("Ford Prefect");
		
		std::cout << "Form: " << pardonForm.getName() 
				  << ", Sign Grade: " << pardonForm.getGradeSign()
				  << ", Exec Grade: " << pardonForm.getGradeExec() << std::endl;
		std::cout << "Bureaucrat: " << vicePresident << std::endl;
		
		vicePresident.signForm(pardonForm);
		vicePresident.executeForm(pardonForm); // Should fail
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	// Test with bureaucrat who cannot sign or execute
	try {
		std::cout << "\nTest 3: Bureaucrat who cannot sign or execute" << std::endl;
		Bureaucrat clerk("Clerk", 30); // Cannot sign (25) or execute (5)
		PresidentialPardonForm pardonForm("Marvin");
		
		std::cout << "Form: " << pardonForm.getName() 
				  << ", Sign Grade: " << pardonForm.getGradeSign()
				  << ", Exec Grade: " << pardonForm.getGradeExec() << std::endl;
		std::cout << "Bureaucrat: " << clerk << std::endl;
		
		clerk.signForm(pardonForm); // Should fail
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

void testFormCopying() {
	std::cout << "===== TESTING FORM COPYING =====" << std::endl;
	
	try {
		Bureaucrat boss("Boss", 1);
		
		// Test ShrubberyCreationForm
		ShrubberyCreationForm originalShrubbery("original");
		boss.signForm(originalShrubbery);
		
		// Copy constructor
		ShrubberyCreationForm copiedShrubbery(originalShrubbery);
		std::cout << "Original ShrubberyCreationForm: " << originalShrubbery.getName() 
				  << ", Signed: " << (originalShrubbery.getSigned() ? "Yes" : "No") << std::endl;
		std::cout << "Copied ShrubberyCreationForm: " << copiedShrubbery.getName() 
				  << ", Signed: " << (copiedShrubbery.getSigned() ? "Yes" : "No") << std::endl;
				  
		// Assignment operator
		ShrubberyCreationForm assignedShrubbery("unused");
		assignedShrubbery = originalShrubbery;
		std::cout << "Assigned ShrubberyCreationForm: " << assignedShrubbery.getName() 
				  << ", Signed: " << (assignedShrubbery.getSigned() ? "Yes" : "No") << std::endl;
		
		// Test RobotomyRequestForm
		RobotomyRequestForm originalRobotomy("R2D2");
		boss.signForm(originalRobotomy);
		
		// Copy constructor
		RobotomyRequestForm copiedRobotomy(originalRobotomy);
		std::cout << "\nOriginal RobotomyRequestForm: " << originalRobotomy.getName() 
				  << ", Signed: " << (originalRobotomy.getSigned() ? "Yes" : "No") << std::endl;
		std::cout << "Copied RobotomyRequestForm: " << copiedRobotomy.getName() 
				  << ", Signed: " << (copiedRobotomy.getSigned() ? "Yes" : "No") << std::endl;
				  
		// Assignment operator
		RobotomyRequestForm assignedRobotomy("unused");
		assignedRobotomy = originalRobotomy;
		std::cout << "Assigned RobotomyRequestForm: " << assignedRobotomy.getName() 
				  << ", Signed: " << (assignedRobotomy.getSigned() ? "Yes" : "No") << std::endl;
				  
		// Test PresidentialPardonForm
		PresidentialPardonForm originalPardon("Zaphod");
		boss.signForm(originalPardon);
		
		// Copy constructor
		PresidentialPardonForm copiedPardon(originalPardon);
		std::cout << "\nOriginal PresidentialPardonForm: " << originalPardon.getName() 
				  << ", Signed: " << (originalPardon.getSigned() ? "Yes" : "No") << std::endl;
		std::cout << "Copied PresidentialPardonForm: " << copiedPardon.getName() 
				  << ", Signed: " << (copiedPardon.getSigned() ? "Yes" : "No") << std::endl;
				  
		// Assignment operator
		PresidentialPardonForm assignedPardon("unused");
		assignedPardon = originalPardon;
		std::cout << "Assigned PresidentialPardonForm: " << assignedPardon.getName() 
				  << ", Signed: " << (assignedPardon.getSigned() ? "Yes" : "No") << std::endl;
				  
		// Execute all copied and assigned forms to ensure they work
		std::cout << "\nExecuting copied and assigned forms:" << std::endl;
		boss.executeForm(copiedShrubbery);
		boss.executeForm(assignedShrubbery);
		boss.executeForm(copiedRobotomy);
		boss.executeForm(assignedRobotomy);
		boss.executeForm(copiedPardon);
		boss.executeForm(assignedPardon);
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}

int main()
{
	testShrubberyCreationForm();
	printSeparator();
	
	testRobotomyRequestForm();
	printSeparator();
	
	testPresidentialPardonForm();
	printSeparator();
	
	testFormCopying();

	return 0;
}