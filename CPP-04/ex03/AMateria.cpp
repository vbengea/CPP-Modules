#include "AMateria.hpp"

AMateria::AMateria() {
	
}

AMateria::AMateria(const AMateria& rhs) : _type(rhs._type) {
	// std::cout << "Copy constructor AMateria called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
		// std::cout << "Copy assignment operator AMateria called" << std::endl;
	}
	return *this;
}


AMateria::~AMateria() {
	// std::cout << "Destructor AMateria called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type) {
	// std::cout << "Constructor with type AMateria called" << std::endl;
}


const std::string& AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
	std::cout << "Testing for now" << std::endl;
}
