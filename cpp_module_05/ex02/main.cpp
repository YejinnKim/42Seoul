#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat b("b", 1);
	ShrubberyCreationForm s("s");
	
	s.beSigned(b);
	s.execute(b);

	return 0;
}
