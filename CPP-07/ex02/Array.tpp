#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), array(NULL) {}

template <typename T>
Array<T>::Array(const Array& rhs) : array(NULL), _size(rhs._size) {
	if (_size > 0) {
		array = new T[_size];
		for (unsigned int i = 0; i < _size; ++i) {
			array[i] = rhs.array[i];
		}
	}
}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), _size(n) {}

template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs) {
	if (this != &rhs) {
		delete[] array;
		_size = rhs._size;
		array = new T[_size];
		for (unsigned int i = 0; i < _size; ++i) {
			array[i] = rhs.array[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] array;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}
