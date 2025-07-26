#include "Span.hpp"
#include "limits.h"
#include <stdexcept>
#include <algorithm>

Span::Span() {
	
}

Span::Span(const Span& rhs) : maxSize(rhs.maxSize), numbers(rhs.numbers) {
	
}

Span::Span(unsigned int N) : maxSize(N) {

}

Span& Span::operator=(const Span& rhs) {
	if (this != &rhs) {
		numbers = rhs.numbers;
		maxSize = rhs.maxSize;
	}
	return *this;
}

Span::~Span() {
	
}


void Span::addNumber(int n) {
	if (numbers.size() >= maxSize) {
		throw std::runtime_error("Container full, cannot add more numbers.");
	}
	numbers.push_back(n);
}


int Span::shortestSpan() {
	if (numbers.size() < 2) {
		throw std::runtime_error("No span can be found.");
	}
	std::vector<int> temp = numbers;
	std::sort(temp.begin(), temp.end());

	int res = INT_MAX;
	for (std::vector<int>::iterator it = temp.begin(); it != temp.end() - 1; it++) {
		int diff = *(it + 1) - *it;
		diff < res ? res = diff : res;
	}
	return res;
}

int Span::longestSpan() {
	if (numbers.size() < 2) {
		throw std::runtime_error("No span can be found,");
	}
	int min = *std::min_element(numbers.begin(), numbers.end());
	int max = *std::max_element(numbers.begin(), numbers.end());
	return max - min;
}

void Span::addMultipleNumbers(typename std::vector<int>::iterator begin, typename std::vector<int>::iterator end) {
	for (std::vector<int>::iterator it = begin; it != end; ++it) {
		addNumber(*it);
	}
}
