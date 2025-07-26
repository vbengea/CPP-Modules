#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stack>

class RPN
{
	public:
		static void evalRPN(const std::string& expression);

	private:
		RPN();
		RPN(const RPN& rhs);
		RPN& operator=(const RPN& rhs);
		~RPN();
};

#endif // RPN_HPP
