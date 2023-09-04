#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat b("yejinkim", 1);
	
		ShrubberyCreationForm s("SForm"); // sign: 145, exec: 137
		RobotomyRequestForm r("RForm"); // sign: 72, exec: 45
		PresidentialPardonForm p("PForm"); // sign: 25, exec: 5

		b.signForm(s);
		b.signForm(r);
		b.signForm(p);

		b.executeForm(s);
		b.executeForm(r);
		b.executeForm(p);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
