#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream file("data.csv");
	if (!file)
		printError("could not open .csv file.", true);

	std::string line;
	std::getline(file, line);
	if (line != "date,exchange_rate")
		printError("invalid data format.", true);

	while (std::getline(file, line))
	{
		size_t pos = line.find(',');
		if (pos == std::string::npos)
			printError("invalid data format.", true);

		std::string date = parseDate(line, pos, true);
		double rate = parseRate(line, pos);

		data.insert(std::pair<std::string, double>(date, rate));
	}
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this != &obj)
		this->data = obj.data;
	return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) { *this = obj; }

BitcoinExchange::~BitcoinExchange() {}

bool	BitcoinExchange::checkFormat(const std::string &date)
{
	int chk = 0;
	for (size_t i = 0; i < date.length(); i++)
	{
		if (!isdigit(date[i]) && !(date[i] == '-' && chk < 2))
			return false;
		if (date[i] == '-')
			chk++;
	}
	return true;
}

bool	BitcoinExchange::checkValid(int year, int month, int day)
{
	if (year < 0 || month < 0 || month > 12 || day < 0 || day > 31)
		return false;
	if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
		return false;
	if (day > 28 && month == 2)
		if (!(day == 29 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))))
			return false;
	return true;
}

std::string	BitcoinExchange::parseDate(const std::string &line, size_t pos, bool exitFlag)
{
	std::string date = line.substr(0, pos);
	if (!checkFormat(date))
		date.clear();

	std::stringstream ss(date);
	std::string tmp;
	int year, month, day;
	for (int i = 0; std::getline(ss, tmp, '-'); i++)
	{
		if (i == 0)
			std::stringstream(tmp) >> year;
		else if (i == 1)
			std::stringstream(tmp) >> month;
		else if (i == 2)
			std::stringstream(tmp) >> day;
	}
	if (!checkValid(year, month, day))
		date.clear();
	
	if (date.empty() && exitFlag)
		printError("invalid date.", true);
	else if (date.empty())
		printError("bad input => " + line, false);

	return date;
}

double	BitcoinExchange::parseRate(const std::string &line, size_t pos)
{
	char *endptr;
	double rate = strtod(line.substr(pos + 1).c_str(), &endptr);

	if (*endptr != '\0')
		printError("invalid exchange rate.", true);
	return rate;
}

double		BitcoinExchange::parseValue(const std::string &line, size_t pos)
{
	char *endptr;
	double value = strtod(line.substr(pos + 3).c_str(), &endptr);

	if (*endptr != '\0')
		printError("invalid value.", false);
	else if (value <= 0)
		printError("not a positive number.", false);
	else if (value >= 1000)
		printError("too large a number.", false);
	else
		return value;
	return -1;
}

double	BitcoinExchange::findRate(const std::string &date)
{
	if (date.empty())
		return -1;

	double rate;
	std::map<std::string, double>::iterator it = data.lower_bound(date);

	if (it != data.end() && it == data.find(date))
		rate = data[date];
	else if (it != data.end() && it != data.begin())
		rate = (--it)->second;
	else
	{
		rate = -1;
		printError("not found date.", false);
	}
	return rate;
}

void	BitcoinExchange::exchange(const std::string &input)
{
	std::ifstream file(input);
	if (!file)
		printError("could not open file.", true);
	
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
		printError("invalid input format.", true);

	while (std::getline(file, line))
	{
		size_t pos = line.find(" | ");
		if (pos == std::string::npos)
		{
			printError("bad input => " + line, false);
			continue;
		}

		std::string date = parseDate(line, pos, false);
		double value = parseValue(line, pos);
		double rate = findRate(date);
		if (date.empty() || value < 0 || rate < 0)
			continue;

		std::cout << date << " => " << value << " = " << value * rate << std::endl;
	}
}

void	printError(std::string str, bool exitFlag)
{
	std::cerr << "Error: " << str << std::endl;
	if (exitFlag)
		exit(1);
}
