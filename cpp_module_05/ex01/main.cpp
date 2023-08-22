#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat b("b", 1);
		// Bureaucrat b("b", 3);
		Form f("f", 1, 2);
		std::cout << b << std::endl;
		std::cout << f << std::endl;

		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}