#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>

class ScalarConverter
{
	private:
		ScalarConverter();
	public:
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter& operator=(const ScalarConverter& obj);
		~ScalarConverter();

		static bool	checkValue(const std::string &input, double value);
		static void	checkDot(double value);
		static void	convertChar(double value);
		static void	convertInt(double value, char sign);
		static void	convertFloat(double value, char sign);
		static void	convertDouble(double value, char sign);
		static void	convert(const std::string &input);
};

#endif
