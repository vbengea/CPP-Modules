#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();

		void loadDatabase(const std::string& filename);
		void processInputFile(const std::string& filename);

	private:
		BitcoinExchange(const BitcoinExchange& rhs);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);

		bool isValidDate(const std::string& date) const;
		bool isValidFloatFormat(const std::string& str) const;

		void calculatePriceForEntry(const std::string& date, float value) const;

		std::map<std::string, float> data;
};

#endif // BITCOINEXCHANGE_HPP
