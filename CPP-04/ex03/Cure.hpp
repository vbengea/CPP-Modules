#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure& rhs);
		Cure& operator=(const Cure& rhs);
		~Cure();

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);

	private:
		
};

#endif // CURE_HPP
