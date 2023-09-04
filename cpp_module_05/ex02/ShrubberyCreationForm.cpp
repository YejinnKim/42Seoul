#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137)
{
	target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref)
	: AForm(ref.getName(), ref.getSignGrade(), ref.getExecuteGrade())
{
	target = ref.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
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

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::cout << executor.getName() << " executed " << getName() << std::endl;
	std::ofstream ofs;
	ofs.open(target + "_shrubbery");
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
