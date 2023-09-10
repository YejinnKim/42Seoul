#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	*this = obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &obj)
{
	if (this != &obj)
		*this = obj;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

bool	ScalarConverter::checkValue(const std::string &input, double value)
{
	int len = input.length();
	int dot = 0;
	int i;
	for (i = 0; i < len; i++)
	{
		if (!(std::isdigit(input[i]) \
			|| (input[i] == '.' && dot == 0) \
			|| ((input[i] == '+' || input[i] == '-') && i == 0) \
			|| (input[i] == 'f' && i == len - 1 && dot == 1)))
			break;
		if (input[i] == '.')
			dot++;
	}
	if (std::isnan(value) || std::isinf(value) || (i == len && \
		(value != 0.0 || (value == 0.0 && input.find("0") != std::string::npos))))
		return true;
	std::cout << "conversion failed!" << std::endl;
	return false;
}

size_t	ScalarConverter::findDot(const std::string &input)
{
	size_t dot = input.find(".");
	size_t i;
	for (i = dot; dot && i < input.length(); i++)
	{
		if (!(input[i] == '.' || input[i] == '0' || input[i] == 'f'))
			break;
	}
	if (i == input.length())
		dot = std::string::npos;
	return dot;
}

void	ScalarConverter::convertChar(double value)
{
	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value))
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(value))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

}

void	ScalarConverter::convertInt(double value)
{
	std::cout << "int: ";
	if (std::isnan(value) || value > INT_MAX || value < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void	ScalarConverter::convertFloat(double value, char sign, size_t dot)
{
	std::cout << "float: ";
	if (std::isnan(value))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(value))
	{
		if (sign == '-' || sign == '+')
			std::cout << sign;
		std::cout << "inff" << std::endl;
	}
	else
	{
		std::cout << static_cast<float>(value);
		if (dot == std::string::npos)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
}

void	ScalarConverter::convertDouble(double value, char sign, size_t dot)
{
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
	{
		if (sign == '-' || sign == '+')
			std::cout << sign;
		std::cout << "inf" << std::endl;
	}
	else
	{
		std::cout << static_cast<double>(value);
		if (dot == std::string::npos)
			std::cout << ".0" << std::endl;
		else
			std::cout << std::endl;
	}
}

void	ScalarConverter::convert(const std::string &input)
{
	double value = std::strtod(input.c_str(), nullptr);
	
	if (!checkValue(input, value))
		return;

	size_t dot = findDot(input);
	char sign = input[0];

	convertChar(value);
	convertInt(value);
	convertFloat(value, sign, dot);
	convertDouble(value, sign, dot);
}
