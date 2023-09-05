#include "AForm.hpp"

AForm::AForm()
	: name("default"), sign(false), signGrade(1), executeGrade(1)
{

}

AForm::AForm(std::string name, int signGrade, int executeGrade)
	: name(name), sign(false), signGrade(signGrade), executeGrade(executeGrade)
{

}

AForm::AForm(const AForm &ref)
	: name(ref.name), sign(ref.sign), signGrade(ref.signGrade), executeGrade(ref.executeGrade)
{

}

AForm& AForm::operator=(const AForm &ref)
{
	if (this != &ref)
	{
		const_cast<std::string&>(name) = ref.getName();
		sign = ref.getSign();
		const_cast<int&>(signGrade) = ref.getSignGrade();
		const_cast<int&>(executeGrade) = ref.getExecuteGrade();
	}
	return *this;
}

AForm::~AForm()
{

}

const std::string&	AForm::getName() const
{
	return name;
}

bool	AForm::getSign() const
{
	return sign;
}

const int&	AForm::getSignGrade() const
{
	return signGrade;
}

const int&	AForm::getExecuteGrade() const
{
	return executeGrade;
}

void	AForm::setName(const std::string &name)
{
	const_cast<std::string&>(this->name) = name;
}

void	AForm::setSign(bool sign)
{
	this->sign = sign;
}

void	AForm::setSignGrade(int signGrade)
{
	const_cast<int&>(this->signGrade) = signGrade;
}

void	AForm::setExecuteGrade(int executeGrade)
{
	const_cast<int&>(this->executeGrade) = executeGrade;
}

void	AForm::beSigned(const Bureaucrat& b)
{
	std::cout << b.getName() << " signed " << name << std::endl;
	sign = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "grade too high.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "grade too low.";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "not signed.";
}

std::ostream& operator<<(std::ostream &out, const AForm &f)
{
	out << std::boolalpha << f.getName() 
		<< ", sign " << f.getSign()
		<< ", signGrade " << f.getSignGrade()
		<< ", executeGrade " << f.getExecuteGrade();
	return (out);
}
