#include "iter.hpp"
#include <iostream>

void times_two(int& n) {
	n = n * 2;
}

void add_prefix(std::string& str) {
	str = "ft_" + str;
}

void add_suffix(std::string& str) {
	str = str + ".cpp";
}

int main() {
	
	int arr[5] = {1, 2, 3, 4, 5};

	for (int i = 0; i < 5; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	iter(arr, 5, times_two);

	for (int i = 0; i < 5; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	std::string libft[3] = {"split", "strtrim", "strjoin"};
	iter(libft, 3, add_prefix);

	for (int i = 0; i < 3; i++) {
		std::cout << libft[i] << std::endl;
	}

	std::string anotherTest[5] = {"42", "hello", "world", "Madrid", "test"};
	iter(anotherTest, 5, add_suffix);

	for (int i = 0; i < 5; i++) {
		std::cout << anotherTest[i] << std::endl;
	}
}

