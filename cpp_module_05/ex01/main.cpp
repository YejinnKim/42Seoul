#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat b("yejinkim", 1);
		// Bureaucrat b("yejinkim", 3);
		Form f("Form", 1, 2);
		// Form f("Form", 0, 2);
		
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
