#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
	public:
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator=(const ScalarConverter& obj);
		~ScalarConverter();

		static bool		checkValue(const std::string &input, double value);
		static size_t	findDot(const std::string &input);
		static void		convertChar(double value);
		static void		convertInt(double value);
		static void		convertFloat(double value, char sign, size_t dot);
		static void		convertDouble(double value, char sign, size_t dot);
		static void		convert(const std::string &input);
};

#endif
