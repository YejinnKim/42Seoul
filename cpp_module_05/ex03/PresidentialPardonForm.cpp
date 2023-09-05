#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5)
{
	target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, std::string target)
	: AForm(name, 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref)
	: AForm(ref.getName(), ref.getSignGrade(), ref.getExecuteGrade())
{
	target = ref.target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
	if (this != &ref)
	{
		setName(ref.getName());
		setSign(ref.getSign());
		setSignGrade(ref.getSignGrade());
		setExecuteGrade(ref.getExecuteGrade());
		target = ref.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	std::cout << executor.getName() << " executed " << getName() << std::endl;
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
