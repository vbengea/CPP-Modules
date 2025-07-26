#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate() {
	std::srand(std::time(NULL));

	int choice = std::rand() % 3;
	switch (choice) {
		case 0: return new A;
		case 1: return new B;
		default: return new C;
	}
}