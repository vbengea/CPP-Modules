#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	Animal* animal = new Animal();
	animal->makeSound();
	delete animal;

	Dog* dog = new Dog();
	dog->makeSound();
	delete dog;

	Animal* dogAsAnimal = new Dog();
	dogAsAnimal->makeSound();
	delete dogAsAnimal;

	Cat* cat = new Cat();
	cat->makeSound();
	delete cat;

	Animal* catAsAnimal = new Cat();
	catAsAnimal->makeSound();
	delete catAsAnimal;
}

// int main()
// {
// 	const WrongAnimal* meta = new WrongAnimal();
// 	// const WrongAnimal* j = new Dog();
// 	const WrongAnimal* i = new WrongCat();
// 	// std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	// j->makeSound();
// 	meta->makeSound();
// 	return 0;
// }

// Subject main -- This main has leaks, delete is not called
// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();
// 	return 0;
// }