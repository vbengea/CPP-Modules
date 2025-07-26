#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++) {
		ideas[i] = "";
	}
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& rhs) {
	for (int i = 0; i < 100; i++) {
		ideas[i] = rhs.ideas[i];
	}
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = rhs.ideas[i];
		}
		std::cout << "Assignment Brain constructor called" << std::endl;
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}


std::string Brain::getIdea(int index) {
	return this->ideas[index];
}

void Brain::setIdea(std::string idea, int index) {
	this->ideas[index] = idea;
}