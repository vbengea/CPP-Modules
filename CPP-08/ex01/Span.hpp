#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span
{
	public:
		Span(const Span& rhs);
		Span(unsigned int N);
		Span& operator=(const Span& rhs);
		~Span();

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();

		void addMultipleNumbers(typename std::vector<int>::iterator begin, typename std::vector<int>::iterator end);

	private:
		Span();
		unsigned int maxSize;
		std::vector<int> numbers;
};

#endif // SPAN_HPP
