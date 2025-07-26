#include "BitcoinExchange.hpp"
#include <iostream>

int main(int arcg, char **argv) {

	if (arcg != 2) {
		std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}

	BitcoinExchange exchange;
	exchange.loadDatabase("data.csv");
	exchange.processInputFile(argv[1]);

	return 0;
}
