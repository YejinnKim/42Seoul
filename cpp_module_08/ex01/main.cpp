#include "Span.hpp"

int main()
{
	// subject test
	Span sp = Span(5);

	// sp.shortestSpan(); // error 
	// sp.longestSpan(); // error

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	// sp.addNumber(11); // error

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// my test
	unsigned int N = 10000;
	Span sp2 = Span(N);

	srand(time(NULL));
	for (unsigned int i = 0; i < N; i++)
		sp2.addNumber(rand() % 100);

	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	return 0;
}
