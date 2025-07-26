#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	// std::cout << "Default constructor Ice called" << std::endl;
}

Ice::Ice(const Ice& rhs) : AMateria(rhs) {
	this->_type = "ice";
	// std::cout << "Copy constructor Ice called" << std::endl;
}

Ice& Ice::operator=(const Ice& rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
		// std::cout << "Copy assignment operator Ice called" << std::endl;
	}
	return *this;
}

Ice::~Ice() {
	// std::cout << "Destructor Ice called" << std::endl;
}


AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout << "Ice: * shoots an ice bolt at " << target.getName() << " *" << std::endl;
	(void)target;
}