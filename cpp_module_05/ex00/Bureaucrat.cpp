#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: name("default"), grade(1)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref)
	: name(ref.name), grade(ref.grade)
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &ref)
{
	if (this != &ref)
		grade = ref.grade;
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
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade == 150)
		throw  Bureaucrat::GradeTooLowException();
	grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (out);
}
