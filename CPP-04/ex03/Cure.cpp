#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	// std::cout << "Default constructor Cure called" << std::endl;
}

Cure::Cure(const Cure& rhs) : AMateria(rhs) {
	this->_type = "cure";
	// std::cout << "Copy constructor Cure called" << std::endl;
}

Cure& Cure::operator=(const Cure& rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
		// std::cout << "Copy assignemnt operator Cure called" << std::endl;
	}
	return *this;
}

Cure::~Cure() {
	// std::cout << "Destructor Cure called" << std::endl;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	std::cout << "Cure: * heals " << target.getName() << "'s wounds *" << std::endl;
	(void)target;
}
