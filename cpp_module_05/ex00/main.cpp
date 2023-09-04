#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("yejinkim", 1);
		std::cout << b << std::endl;
		b.decrementGrade();
		b.decrementGrade();
		b.decrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;

		// Bureaucrat test("test", 0);
		
		// Bureaucrat test("test", 1);
		// std::cout << test << std::endl;
		// test.incrementGrade();

		// Bureaucrat test("test", 150);
		// std::cout << test << std::endl;
		// test.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
