#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.shortestSpan(); // error 
	sp.longestSpan(); // error

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.addNumber(11); // error

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl << std::endl;

	// --- Many Numbers ---
	Span sp2 = Span(10000);

	sp2.addManyNumbers();
	// sp2.printNumber();

	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	return 0;
}
