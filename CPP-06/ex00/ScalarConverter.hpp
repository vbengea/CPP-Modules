#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

enum InputType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	LITERAL,
	INVALID
};


class ScalarConverter
{
	public:
		static void convert(const std::string& str);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& rhs);
		ScalarConverter& operator=(const ScalarConverter& rhs);
		~ScalarConverter();

		static InputType getInputType(const std::string& str);
		static void handleLiteral(const std::string& str);
		static void displayChar(double value);
		static void displayInt(double value);
		static void displayFloat(double value);
		static void displayDouble(double value);

};

#endif // SCALARCONVERTER_HPP
