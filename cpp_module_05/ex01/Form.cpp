#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: name("default"), sign(false), signGrade(1), executeGrade(1)
{

}

Form::Form(std::string name, int signGrade, int executeGrade)
	: name(name), sign(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &ref)
	: name(ref.name), sign(ref.sign), signGrade(ref.signGrade), executeGrade(ref.executeGrade)
{

}

Form& Form::operator=(const Form &ref)
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

Form::~Form()
{

}

const std::string&	Form::getName() const
{
	return name;
}

bool	Form::getSign() const
{
	return sign;
}

const int&	Form::getSignGrade() const
{
	return signGrade;
}

const int&	Form::getExecuteGrade() const
{
	return executeGrade;
}

void	Form::beSigned(Bureaucrat& b)
{
	std::cout << b.getName() << " signed " << name << std::endl;
	sign = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "grade too high.";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "grade too low.";
}

std::ostream& operator<<(std::ostream &out, const Form &f)
{
	out << std::boolalpha << f.getName() 
		<< ", sign " << f.getSign()
		<< ", signGrade " << f.getSignGrade()
		<< ", executeGrade " << f.getExecuteGrade();
	return (out);
}
