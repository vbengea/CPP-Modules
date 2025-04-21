#ifndef FILEREPLACER_HPP
# define FILEREPLACER_HPP

#include <iostream>
#include <fstream>
#include <cstring>

class FileReplacer
{
	public:
		FileReplacer(const std::string& file, const std::string& search, const std::string& replace); // Constructor
		~FileReplacer(); // Destructor

		bool processFile();

	private:
		// Add member variables here
		std::string filename;
		std::string searchStr;
		std::string replaceStr;
};

#endif // FILEREPLACER_HPP
