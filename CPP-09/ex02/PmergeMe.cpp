#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	
}

PmergeMe::PmergeMe(const PmergeMe& rhs) {
	(void)rhs;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
	if (this != &rhs) {
		(void)rhs;
	}
	return *this;
}

PmergeMe::~PmergeMe() {
	
}


void PmergeMe::sortVector(std::vector<int>& vec) {
	std::vector<int> bigs;
	std::vector<int> smalls;

	bool hasLastOdd = false;
	int lastOdd = 0;
	if (vec.size() % 2 != 0) {
		hasLastOdd = true;
		lastOdd = vec.back();
		vec.pop_back();
	}

	for (size_t i = 0; i < vec.size(); i += 2) {
		if (vec[i] < vec[i + 1]) {
			smalls.push_back(vec[i]);
			bigs.push_back(vec[i + 1]);
		} else {
			bigs.push_back(vec[i]);
			smalls.push_back(vec[i + 1]);
		}
	}

	std::sort(bigs.begin(), bigs.end());

	std::vector<int>::iterator it = smalls.begin();
	for (; it != smalls.end(); it++) {
		std::vector<int>::iterator inser = std::lower_bound(bigs.begin(), bigs.end(), *it);
		bigs.insert(inser, *it);
	}

	if (hasLastOdd) {
		std::vector<int>::iterator inser = std::lower_bound(bigs.begin(), bigs.end(), lastOdd);
		bigs.insert(inser, lastOdd);
	}
	vec = bigs;
}


void PmergeMe::sortDeque(std::deque<int>& deq) {
	std::deque<int> bigs;
	std::deque<int> smalls;

	bool hasLastOdd = false;
	int lastOdd = 0;
	if (deq.size() % 2 != 0) {
		hasLastOdd = true;
		lastOdd = deq.back();
		deq.pop_back();
	}

	for (size_t i = 0; i < deq.size(); i += 2) {
		if (deq[i] < deq[i + 1]) {
			smalls.push_back(deq[i]);
			bigs.push_back(deq[i + 1]);
		} else {
			bigs.push_back(deq[i]);
			smalls.push_back(deq[i + 1]);
		}
	}

	std::sort(bigs.begin(), bigs.end());

	std::deque<int>::iterator it = smalls.begin();
	for (; it != smalls.end(); it++) {
		std::deque<int>::iterator inser = std::lower_bound(bigs.begin(), bigs.end(), *it);
		bigs.insert(inser, *it);
	}

	if (hasLastOdd) {
		std::deque<int>::iterator inser = std::lower_bound(bigs.begin(), bigs.end(), lastOdd);
		bigs.insert(inser, lastOdd);
	}
	deq = bigs;
}
