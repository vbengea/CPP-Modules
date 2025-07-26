#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& rhs);
		MateriaSource& operator=(const MateriaSource& rhs);
		~MateriaSource();

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);

	private:
		AMateria* _materia[4];
};

#endif // MATERIASOURCE_HPP
