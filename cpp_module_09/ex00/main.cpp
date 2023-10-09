#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		printError("could not open file.", true);

	BitcoinExchange btc;
	btc.exchange(argv[1]);

	return 0;
}
