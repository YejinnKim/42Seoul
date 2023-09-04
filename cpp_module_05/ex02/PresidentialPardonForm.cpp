#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("default", 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string name)
	: AForm(name, 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref)
	: AForm(ref.getName(), ref.getSignGrade(), ref.getExecuteGrade())
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
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

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
