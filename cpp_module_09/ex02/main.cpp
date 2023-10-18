#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
		printError();

	PmergeMe p(argc, argv);

	std::cout << "Before:	";
	p.printVector();
	
	p.sortVector();
	p.sortList();
	
	std::cout << "After:	";
	p.printVector();

	p.printTime();

	return 0;
}
