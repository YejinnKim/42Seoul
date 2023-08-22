#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("a", 1);
		std::cout << a << std::endl;
		a.decrementGrade();
		a.decrementGrade();
		a.decrementGrade();
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;

		// Bureaucrat b("b", 0);

		// Bureaucrat c("c", 1);
		// std::cout << c << std::endl;
		// c.incrementGrade();

		// Bureaucrat d("d", 150);
		// std::cout << d << std::endl;
		// d.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}