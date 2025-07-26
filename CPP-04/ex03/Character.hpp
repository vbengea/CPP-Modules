#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	public:
		~Character();

		Character(const Character& rhs);
		Character& operator=(const Character& rhs);
		Character(std::string name);


		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		AMateria* getMateria(int idx) const;

	private:
		AMateria* _materia[4];
		std::string _name;
		Character();
};
#endif // CHARACTER_HPP
