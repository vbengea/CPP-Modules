#include "Zombie.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <number_of_zombies>" << std::endl;
		return 1;
	}
	int N = atoi(argv[1]);
	Zombie* horde = zombieHorde(N, "");
	for (int i = 0; i < N; i++) {
		std::stringstream ss;
		ss << "Zombie" << (i + 1);
		horde[i].setName(ss.str());
	}
	if (!horde) {
		std::cerr << "Failed to create zombie horde." << std::endl;
		return 1;
	}

	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}

	delete[] horde;
	return 0;
}