#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
	private:
		AMateria();
	protected:
		// [...]
		std::string _type;
	public:
		// Construcrtors
		AMateria(std::string const & type);
		AMateria(AMateria const & rhs);
		AMateria& operator=(AMateria const & rhs);
		// Destructor
		virtual ~AMateria();
		// [...]
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif // AMATERIA_HPP


