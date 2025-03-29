#include "FileReplacer.hpp"

FileReplacer::FileReplacer(const std::string& file, const std::string& search, const std::string& replace)
	: filename(file), searchStr(search), replaceStr(replace) {
	// Constructor implementation
}

FileReplacer::~FileReplacer() {
	// Destructor implementation
}

bool FileReplacer::processFile() {
	std::ifstream file(filename.c_str());
	if (!file) {
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return (false);
	}

	std::string text;
	std::string result;

	while (std::getline(file, text)) {
		size_t pos = 0;
		while ((pos = text.find(searchStr, pos)) != std::string::npos) {
			text.erase(pos, searchStr.length());
			text.insert(pos, replaceStr);
			pos += replaceStr.length();
		}
		result += text + "\n";
	}
	file.close();
	if (result.empty()) {
		std::cerr << "Error: No content to write to file" << std::endl;
		return (false);
	}

	std::ofstream outfile(filename.c_str());
	if (!outfile) {
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return (false);
	}
	outfile << result;
	outfile.close();

	return (true);
}
