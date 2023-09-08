#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: name("default"), grade(1)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref)
	: name(ref.name), grade(ref.grade)
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &ref)
{
	if (this != &ref)
	{
		const_cast<std::string&>(name) = ref.getName();
		grade = ref.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{

}

const std::string&	Bureaucrat::getName() const
{
	return name;
}

int	Bureaucrat::getGrade() const
{
	return grade;
}

void	Bureaucrat::incrementGrade()
{
	if (grade == 1)
		throw GradeTooHighException();
	grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (grade == 150)
		throw  GradeTooLowException();
	grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade too low.";
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (out);
}
