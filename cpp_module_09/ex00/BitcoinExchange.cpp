#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream file("data.csv");
	if (!file)
		printError("could not open data file.", true);

	std::string line;
	std::getline(file, line);
	if (line != "date,exchange_rate")
		printError("invalid data.", true);

	while (std::getline(file, line))
	{
		size_t pos = line.find(',');
		if (pos == std::string::npos)
			printError("invalid data.", true);

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

std::string	BitcoinExchange::parseDate(const std::string &line, size_t pos, bool exitFlag)
{
	std::string date = line.substr(0, pos);
	for (size_t i = 0; i < date.length(); i++)
		if (!isdigit(date[i]) && date[i] != '-')
			date.clear();

	std::stringstream ss(date);
	std::string tmp;
	int year, month, day;

	std::getline(ss, tmp, '-');
	std::stringstream(tmp) >> year;
	if (year < 0)
		date.clear();
	std::getline(ss, tmp, '-');
	std::stringstream(tmp) >> month;
	if (month < 0 || month > 12)
		date.clear();
	
	std::getline(ss, tmp, '-');
	std::stringstream(tmp) >> day;
	if (day < 0 || day > 31)
		date.clear();
	else if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
		date.clear();
	else if (day > 28 && month == 2)
		if (!(day == 29 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))))
			date.clear();
	
	if (std::getline(ss, tmp, '-'))
		date.clear();

	if (date.empty() && exitFlag)
		printError("invalid data.", true);
	else if (date.empty())
		printError("invalid input date.", false);

	return date;
}

double	BitcoinExchange::parseRate(const std::string &line, size_t pos)
{
	char *endptr;
	double rate = strtod(line.substr(pos + 1).c_str(), &endptr);

	if (*endptr != '\0')
		printError("invalid data.", true);
	return rate;
}

double		BitcoinExchange::parseValue(const std::string &line, size_t pos)
{
	char *endptr;
	double value = strtod(line.substr(pos + 3).c_str(), &endptr);

	if (*endptr != '\0')
		printError("invalid input.", false);
	else if (value < 0)
		printError("not a positive number.", false);
	else if (value > 1000)
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
	else if (it != data.end())
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
		printError("invalid input.", true);

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
