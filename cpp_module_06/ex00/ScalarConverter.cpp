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
	if (isnan(value) || isinf(value) \
		|| (i == len && (value != 0.0 || (value == 0.0 && input.find("0") != std::string::npos))))
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
	if (isnan(value) || value > std::numeric_limits<char>::max() || value < std::numeric_limits<char>::min())
		std::cout << "impossible" << std::endl;
	else if (!isprint(value))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

}

void	ScalarConverter::convertInt(double value)
{
	std::cout << "int: ";
	if (isnan(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void	ScalarConverter::convertFloat(double value, char sign)
{
	std::cout << "float: ";
	if (isnan(value))
		std::cout << "nanf" << std::endl;
	else if (isinf(value) || value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::min())
	{
		if (sign == '-' || sign == '+')
			std::cout << sign;
		std::cout << "inff" << std::endl;
	}
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

void	ScalarConverter::convertDouble(double value, char sign)
{
	std::cout << "double: ";
	if (isnan(value))
		std::cout << "nan" << std::endl;
	else if (isinf(value) || value > std::numeric_limits<double>::max() || value < std::numeric_limits<double>::min())
	{
		if (sign == '-' || sign == '+')
			std::cout << sign;
		std::cout << "inf" << std::endl;
	}
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void	ScalarConverter::convert(const std::string &input)
{
	double value = std::strtod(input.c_str(), nullptr);
	
	std::cout << "float: " << static_cast<float>(value) << std::endl
		<< "double: " << static_cast<double>(value) << std::endl << std::endl;	
	
	if (input.length() == 1 && !isdigit(input[0]))
		value = static_cast<double>(input[0]);
	else if (!checkValue(input, value))
		return;

	convertChar(value);
	convertInt(value);
	convertFloat(value, input[0]);
	convertDouble(value, input[0]);
}
