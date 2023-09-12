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
	int chk = 0;
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
		if (dot && input[i] > '0')
			chk++;
	}		
	if ((!dot && ((!isdigit(input[0]) && len < 8) || (isdigit(input[0]) && len < 7))) || (dot && !chk))
		std::cout << std::fixed << std::setprecision(1);
	if (isnan(value) || isinf(value) \
		|| (i == len && (value != 0.0 || (value == 0.0 && input.find("0") != std::string::npos))))
		return true;
	std::cout << "conversion failed!" << std::endl;
	return false;
}

void	ScalarConverter::convertChar(double value)
{
	std::cout << "char: ";
	if (isnan(value) || value > std::numeric_limits<char>::max() || value < std::numeric_limits<char>::lowest())
		std::cout << "impossible" << std::endl;
	else if (!isprint(value))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void	ScalarConverter::convertInt(double value, char sign)
{
	std::cout << "int: ";
	if (isnan(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::lowest())
		std::cout << "impossible" << std::endl;
	else
	{
		if (sign == '+')
			std::cout << sign;
		std::cout << static_cast<int>(value) << std::endl;
	}
}

void	ScalarConverter::convertFloat(double value, char sign)
{
	std::cout << "float: ";
	if (isnan(value))
		std::cout << "nanf" << std::endl;
	else
	{
		if (sign == '+')
			std::cout << sign;
		if (isinf(value) || value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::lowest())
		{
			if (sign == '-')
				std::cout << sign;
			std::cout << "inff" << std::endl;
		}
		else
			std::cout << static_cast<float>(value) << "f" << std::endl;
	}
}

void	ScalarConverter::convertDouble(double value, char sign)
{
	std::cout << "double: ";
	if (isnan(value))
		std::cout << "nan" << std::endl;
	else
	{
		if (sign == '+')
			std::cout << sign;
		if (isinf(value) || value > std::numeric_limits<double>::max() || value < std::numeric_limits<double>::lowest())
		{
			if (sign == '-')
				std::cout << "inf" << std::endl;
		}
		else
			std::cout << static_cast<double>(value) << std::endl;
	}
}

void	ScalarConverter::convert(const std::string &input)
{
	double value = std::strtod(input.c_str(), nullptr);
	// 123456.1 (6자리 + 소수점)
	std::cout << "int: " << static_cast<int>(value) << std::endl
		<< "float: " << static_cast<float>(value) << std::endl
		<< "double: " << static_cast<double>(value) << std::endl << std::endl;

	if (input.length() == 1 && !isdigit(input[0]))
		value = static_cast<double>(input[0]);
	else if (!checkValue(input, value))
		return;

	convertChar(value);
	convertInt(value, input[0]);
	convertFloat(value, input[0]);
	convertDouble(value, input[0]);
}
