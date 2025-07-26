#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <number to find>" << std::endl;
		return 1;
	}

	int n;
	try {
		n = atoi(argv[1]); // std::stoi
	} catch (...) {
		std::cerr << "Invalid argument" << std::endl;
		return 2;
	}

	std::vector<int> ints;

	for (int i = 0; i < 10; i++) {
		ints.push_back(i);
	}

	try {
		std::cout << easyfind(ints, n) << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
