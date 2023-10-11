#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
		printError();

	PmergeMe p;
	p.init(argc, argv);
	p.sort();

	return 0;
}
