#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
int easyfind(const T& a, int b) {
	typename T::const_iterator ite = std::find(a.begin(), a.end(), b);
	if (ite != a.end()) {
		return *ite;
	}
	throw std::runtime_error("Value not found");
}

#endif
