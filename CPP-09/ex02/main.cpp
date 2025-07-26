#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "PmergeMe.hpp"
#include <time.h>

void printContainer(std::vector<int>& vec) {
	std::vector<int>::iterator ite = vec.begin();
	int sizePrint = vec.size() > 5 ? 5 : vec.size();
	int i = 0;
	for (; ite != vec.end(); ite++) {
		if (i < sizePrint) {
			std::cout << *ite << " ";
			i++;
		}
		else
			break ;
	}
	if (vec.size() > 5) {
		std::cout << "[...] " << vec.back();
	}
	std::cout << std::endl;
}

void printContainer(std::deque<int>& deq) {
	std::deque<int>::iterator ite = deq.begin();
	int sizePrint = deq.size() > 5 ? 5 : deq.size();
	int i = 0;
	for (; ite != deq.end(); ite++) {
		if (i < sizePrint) {
			std::cout << *ite << " ";
			i++;
		}
		else
			break;
	}
	if (deq.size() > 5) {
		std::cout << " [...] " << deq.back();
	}
	std::cout << std::endl;
}


int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <number 1> <number 2> ... <number n>" << std::endl;
		return 1;
	}

	std::vector<int> vec;
	std::deque<int> deq;

	for (int i = 1; i < argc; i++) {
		int number;
		std::istringstream iss(argv[i]);

		iss >> number;
		if (number < 0 || iss.fail() || !iss.eof()) {
			std::cerr << "Error" << std::endl;
			return 2;
		}
		vec.push_back(number);
		deq.push_back(number);
	}

	PmergeMe sort;

	struct timespec start, end;

	std::cout << "Before: ";
	printContainer(deq);
	std::cout << "After: ";
	clock_gettime(CLOCK_MONOTONIC, &start);
	sort.sortDeque(deq);
	clock_gettime(CLOCK_MONOTONIC, &end);
	printContainer(deq);

	double timeTaken = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_nsec - start.tv_nsec) / 1e3;

	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: "
				<< std::fixed << std::setprecision(5) << timeTaken << " us" << std::endl;


	clock_gettime(CLOCK_MONOTONIC, &start);
	sort.sortVector(vec);
	clock_gettime(CLOCK_MONOTONIC, &end);
	timeTaken = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_nsec - start.tv_nsec) / 1e3;


	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: "
				<< std::fixed << std::setprecision(5) << timeTaken << " us" << std::endl;

	return 0;
}
