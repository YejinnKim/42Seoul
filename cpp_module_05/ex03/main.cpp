#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat b("yejinkim", 1);
		Intern intern;
		AForm* form;
		
		form = intern.makeForm("robotomy request", "Bender");
		// form = intern.makeForm("presidential pardon", "Bender");
		// form = intern.makeForm("shrubbery creation", "Bender");
		// form = intern.makeForm("test request", "Bender");

		b.signForm(*form);
		b.executeForm(*form);
		delete form;
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
