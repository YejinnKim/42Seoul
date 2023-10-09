#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> data;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange& operator=(const BitcoinExchange &obj);
		~BitcoinExchange();

		bool		checkFormat(const std::string &date);
		bool		checkValid(int year, int month, int day);
		std::string	parseDate(const std::string &line, size_t pos, bool exitFlag);
		double		parseRate(const std::string &line, size_t pos);
		double		parseValue(const std::string &line, size_t pos);
		double		findRate(const std::string &date);
		void		exchange(const std::string &input);
};

void	printError(std::string str, bool exitFlag);

#endif
