#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("default", 145, 137)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)
	: AForm(name, 145, 137)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref)
	: AForm(ref.getName(), ref.getSignGrade(), ref.getExecuteGrade())
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
{
	if (this != &ref)
		setSign(ref.getSign());
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (getSign() == false)
	{
		std::cerr << executor.getName() << " couldn’t execute " << getName() << " because ";
		throw NotSignedException();
	}
	if (executor.getGrade() > getExecuteGrade())
	{
		std::cerr << executor.getName() << " couldn’t execute " << getName() << " because ";
		throw GradeTooLowException();	
	}
	std::ofstream ofs;
	ofs.open(executor.getName() + "_shrubbery");
	ofs <<	"	         ,@@@@@@@,\n"
			"    ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
			" ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
			",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88\'\n"
			"%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888\'\n"
			"%&&%/ %&%%&&@@\\ V /@@\' `88\\8 `/88\'\n"
			"`&%\\ ` /%&\'    |.|        \\ \'|8\'\n"
			"    |o|        | |         | |\n"
			"    |.|        | |         | |\n"
			"_\\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__\n";
	ofs.close();
}
