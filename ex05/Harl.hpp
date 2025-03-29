#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	public:
		Harl(); // Constructor
		~Harl(); // Destructor

		void complain(std::string level);

	private:
		// Add member variables here
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

		typedef void (Harl::*HarlFunc)(void);
		enum Level
		{
			DEBUG,
			INFO,
			WARNING,
			ERROR,
			UNKNOWN
		};
		Level getLevel(std::string level);
};

#endif // HARL_HPP
