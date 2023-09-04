#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("default", 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string name)
	: AForm(name, 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref)
	: AForm(ref.getName(), ref.getSignGrade(), ref.getExecuteGrade())
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
	if (this != &ref)
	{
		setName(ref.getName());
		setSign(ref.getSign());
		setSignGrade(ref.getSignGrade());
		setExecuteGrade(ref.getExecuteGrade());
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	std::cout << "drrrrr! ";
	if (rand() % 2)
		std::cout << executor.getName() << " has been robotomized successfully." << std::endl;
	else
		std::cout << executor.getName() << " has failed to be robotomized." << std::endl;
}
