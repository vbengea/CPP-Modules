#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		this->_materia[i] = NULL;
	}
	// std::cout << "Default constructor MateriaSource called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& rhs) {
	for (int i = 0; i < 4; i++) {
		if (rhs._materia[i]) {
			this->_materia[i] = rhs._materia[i]->clone();
		} else {
			this->_materia[i] = NULL;
		}
	}
	// std::cout << "Copy constructor MateriaSource called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 4; i++) {
			if (this->_materia[i]) {
				delete this->_materia[i];
				this->_materia[i] = NULL;
			}
			if (rhs._materia[i]) {
				this->_materia[i] = rhs._materia[i]->clone();
			} else {
				this->_materia[i] = NULL;
			}
		}
		// std::cout << "Copy assignment operator MateriaSource called" << std::endl;
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i]) {
			delete this->_materia[i];
			this->_materia[i] = NULL;
		}
	}
	// std::cout << "Destructor MateriaSource called" << std::endl;
}


void MateriaSource::learnMateria(AMateria* m) {
	if (m == NULL) {
		// std::cout << "Materia is NULL" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] == NULL) {
			this->_materia[i] = m;
			// std::cout << "Materia " << m->getType() << " learned" << std::endl;
			return;
		}	
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (this->_materia[i] && this->_materia[i]->getType() == type) {
			// std::cout << "Materia " << type << " created" << std::endl;
			return this->_materia[i]->clone();
		}
	}
	// std::cout << "Materia " << type << " not found" << std::endl;
	return NULL;
}



