#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	(void)obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)obj;
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

void	ScalarConverter::checkDot(double value)
{
	std::stringstream ss;
	ss << value;
	std::string str = ss.str();
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		if (!(isdigit(str[i]) || str[i] == '-'))
			return;
	}
	if (str[0] == '-')
		len--;
	if (str.find(".") == std::string::npos && len < 7)
		std::cout << std::fixed << std::setprecision(1);
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
				std::cout << "-";
			std::cout << "inf" << std::endl;
		}
		else
			std::cout << static_cast<double>(value) << std::endl;
	}
}

void	ScalarConverter::convert(const std::string &input)
{
	double value = std::strtod(input.c_str(), nullptr);

	if (input.length() == 1 && !isdigit(input[0]))
		value = static_cast<double>(input[0]);
	else if (!checkValue(input, value))
		return;
	checkDot(value);

	convertChar(value);
	convertInt(value, input[0]);
	convertFloat(value, input[0]);
	convertDouble(value, input[0]);
}
