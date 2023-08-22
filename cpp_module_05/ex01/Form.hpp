#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				sign;
		const int			signGrade;
		const int			executeGrade;
	public:
		Form();
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form &ref);
		Form& operator=(const Form &ref);
		~Form();

		const std::string&	getName() const;
		bool				getSign() const;
		const int&			getSignGrade() const;
		const int&			getExecuteGrade() const;

		void	beSigned(Bureaucrat& b);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, const Form &f);

#endif
