#include "FileReplacer.hpp"


int main(int argc, char *argv[])
{
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	FileReplacer replacer(argv[1], argv[2], argv[3]);

	if (!replacer.processFile()) {
		std::cerr << "Error processing file" << std::endl;
		return (1);
	}
	std::cout << "File processed successfully" << std::endl;
	return (0);
}

// int main(int argc, char *argv[])
// {
// 	if (argc != 4)
// 	{
// 		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
// 		return 1;
// 	}
// 	std::string text;
// 	std::string result;

// 	std::ifstream file(argv[1]);
// 	if (!file)
// 	{
// 		std::cerr << "Error: Could not open file " << argv[1] << std::endl;
// 		return 1;
// 	}
// 	while (std::getline(file, text))
// 	{
// 		size_t pos = 0;
// 		while ((pos = text.find(argv[2], pos)) != std::string::npos)
// 		{
// 			text.erase(pos, strlen(argv[2]));
// 			text.insert(pos, argv[3]);
// 			pos += strlen(argv[3]);
// 		}
// 		result += text + "\n";
// 	}
// 	file.close();

// 	if (result.empty())
// 	{
// 		std::cerr << "Error: No content to write to file" << std::endl;
// 		return 1;
// 	}
// 	std::ofstream outfile(argv[1]);

// 	if (!outfile)
// 	{
// 		std::cerr << "Error: Could not open file " << argv[1] << std::endl;
// 		return 1;
// 	}

// 	outfile << result;
// 	outfile.close();
// }
