#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();

		void sortVector(std::vector<int>& vec);
		void sortDeque(std::deque<int>& deq);

	private:
		PmergeMe(const PmergeMe& rhs);
		PmergeMe& operator=(const PmergeMe& rhs);
};

#endif // PMERGEME_HPP
