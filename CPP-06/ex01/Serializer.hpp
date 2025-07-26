#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"

class Serializer
{
	public:
		static unsigned long serialize(Data* ptr);
		static Data* deserialize(unsigned long raw);
	private:
		Serializer();
		Serializer(const Serializer& rhs);
		Serializer& operator=(const Serializer& rhs);
		~Serializer();
};

#endif // SERIALIZER_HPP
