#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <stdexcept>

template<typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& rhs);
		Array& operator=(const Array& rhs);
		~Array();

		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;

		unsigned int size() const;

	private:
		T* array;
		unsigned int _size;
};


#include "Array.tpp"

#endif // ARRAY_HPP
