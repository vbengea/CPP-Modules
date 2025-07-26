#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"


// int main()
// {
// 	const Animal* arr[100];

// 	for (int i = 0; i < 100; i++) {
// 		if (i < 50) {
// 			arr[i] = new Dog();
// 		}
// 		else {
// 			arr[i] = new Cat();
// 		}
// 	}

// 	std::cout << "Animal at index 5 says ";
// 	arr[5]->makeSound();

// 	std::cout << "Animal at index 55 says ";
// 	arr[55]->makeSound();

// 	const Dog* dog = dynamic_cast<const Dog*>(arr[17]);
// 	if (dog) {
// 		dog->getBrain()->setIdea("I love bones!", 0);
// 		std::cout << "Dog's idea: " << dog->getBrain()->getIdea(0) << std::endl;
// 	}

// 	const Cat* cat = dynamic_cast<const Cat*>(arr[89]);
// 	if (cat) {
// 		cat->getBrain()->setIdea("I love fish!", 0);
// 		std::cout << "Cat's idea: " << cat->getBrain()->getIdea(0) << std::endl;
// 	}

// 	for (int i = 0; i < 100; i++) {
// 		delete arr[i];
// 	}

// }


int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	// ...
	return 0;
}
