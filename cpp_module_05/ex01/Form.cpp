#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: name("default"), sign(false), signGrade(1), executeGrade(1)
{

}

Form::Form(std::string name, int signGrade, int executeGrade)
	: name(name), sign(false), signGrade(signGrade), executeGrade(executeGrade)
{

}

Form::Form(const Form &ref)
	: name(ref.name), sign(ref.sign), signGrade(ref.signGrade), executeGrade(ref.executeGrade)
{

}

Form& Form::operator=(const Form &ref)
{
	if (this != &ref)
		sign = ref.sign;
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
	if (b.getGrade() <= signGrade && b.getGrade() <= executeGrade)
	{
		sign = true;
		std::cout << b.getName() << " signed " << name << std::endl;
	}
	else
	{
		std::cerr << b.getName() << " couldn’t sign " << name << " because ";
		throw GradeTooLowException();
	}
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
