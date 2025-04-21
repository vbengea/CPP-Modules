#include <iostream>

int main(void)
{
	std::string zombie = "HI THIS IS BRAIN";
	std::string* zombiePTR = &zombie;
	std::string& zombieREF = zombie;


	std::cout << &zombie << std::endl;
	std::cout << &zombiePTR << std::endl;
	std::cout << &zombieREF << std::endl;

	std::cout << zombie << std::endl;
	std::cout << *zombiePTR << std::endl;
	std::cout << zombieREF << std::endl;


	return 0;
}
