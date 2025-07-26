#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

// int main()
// {
// 	std::list<int> mstack;
// 	mstack.push_back(5);
// 	mstack.push_back(17);
// 	std::cout << mstack.back() << std::endl;
// 	mstack.pop_back();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(737);
// 	//[...]
// 	mstack.push_back(0);
// 	std::list<int>::iterator it = mstack.begin();
// 	std::list<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::list<int> s(mstack);
// 	return 0;
// }

// int main()
// {
// 	std::vector<int> mstack;
// 	mstack.push_back(5);
// 	mstack.push_back(17);
// 	std::cout << mstack.back() << std::endl;
// 	mstack.pop_back();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(737);
// 	//[...]
// 	mstack.push_back(0);
// 	std::vector<int>::iterator it = mstack.begin();
// 	std::vector<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::vector<int> s(mstack);
// 	return 0;
// }


// int main()
// {
// 	std::cout << "=== Testing MutantStack with integers ===" << std::endl;
// 	MutantStack<int> intStack;
	
// 	for (int i = 1; i <= 5; i++) {
// 		intStack.push(i * 10);
// 	}
	
// 	std::cout << "Stack size: " << intStack.size() << std::endl;
// 	std::cout << "Top element: " << intStack.top() << std::endl;

// 	std::cout << "\nForward iteration:" << std::endl;
// 	for (MutantStack<int>::iterator it = intStack.begin(); it != intStack.end(); ++it) {
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;

// 	std::cout << "\nReverse iteration:" << std::endl;
// 	for (MutantStack<int>::reverse_iterator it = intStack.rbegin(); it != intStack.rend(); ++it) {
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;

// 	std::cout << "\n=== Testing MutantStack with strings ===" << std::endl;
// 	MutantStack<std::string> stringStack;
	
// 	stringStack.push("Hello");
// 	stringStack.push("World");
// 	stringStack.push("from");
// 	stringStack.push("MutantStack");
	
// 	std::cout << "Stack size: " << stringStack.size() << std::endl;
// 	std::cout << "Top element: " << stringStack.top() << std::endl;
	
// 	std::cout << "\n=== Testing copy constructor ===" << std::endl;
// 	MutantStack<std::string> copyStack(stringStack);
	
// 	std::cout << "Original stack size: " << stringStack.size() << std::endl;
// 	std::cout << "Copied stack size: " << copyStack.size() << std::endl;
	
// 	copyStack.pop();
// 	std::cout << "After popping from copy - Original top: " << stringStack.top() << std::endl;
// 	std::cout << "After popping from copy - Copy top: " << copyStack.top() << std::endl;
	
// 	std::cout << "\n=== Testing const iterators ===" << std::endl;
// 	const MutantStack<int> constStack(intStack);
	
// 	std::cout << "Const stack forward iteration:" << std::endl;
// 	for (MutantStack<int>::const_iterator it = constStack.begin(); it != constStack.end(); ++it) {
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;
	
// 	std::cout << "Const stack reverse iteration:" << std::endl;
// 	for (MutantStack<int>::const_reverse_iterator it = constStack.rbegin(); it != constStack.rend(); ++it) {
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;
	
// 	return 0;
// }
