#include "RPN.hpp"

RPN::RPN() {
	
}

RPN::RPN(const RPN& rhs) {
	(void)rhs;
}

RPN& RPN::operator=(const RPN& rhs) {
	if (this != &rhs) {
		(void)rhs;
	}
	return *this;
}

RPN::~RPN() {
	
}


void RPN::evalRPN(const std::string& expression) {
	std::istringstream iss(expression);
	std::string token;
	std::stack<int> rpn;

	while (iss >> token) {
		if (token.length() == 1 && isdigit(token[0])) {
			rpn.push(token[0] - '0');
		}

		else if (token.length() == 1 && (token[0] == '-' || token[0] == '*' || token[0] == '/' || token[0] == '+')) {
			if (rpn.size() < 2) {
				std::cerr << "Too few numbers." << std::endl;
				return;
			} else {
				int secondValue = rpn.top();
				rpn.pop();
				int firstValue = rpn.top();
				rpn.pop();
				if (token[0] == '-') {
					rpn.push(firstValue - secondValue);
				} else if (token[0] == '*') {
					rpn.push(firstValue * secondValue);
				} else if (token[0] == '/') {
					if (secondValue == 0) {
						std::cerr << "Error: division by 0." << std::endl;
						return;
					} else {
						rpn.push(firstValue / secondValue);
					}
				} else {
					rpn.push(firstValue + secondValue);
				}
			}
		}
		else {
			std::cerr << "Invalid input." << std::endl;
			return;
		}
	}

	if (rpn.size() != 1) {
		std::cerr << "Invalid RPN expression." << std::endl;
		return;
	}
	std::cout << rpn.top() << std::endl;
}
