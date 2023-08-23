#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				sign;
		const int			signGrade;
		const int			executeGrade;
	public:
		AForm();
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(const AForm &ref);
		AForm& operator=(const AForm &ref);
		virtual ~AForm();

		const std::string&	getName() const;
		bool				getSign() const;
		const int&			getSignGrade() const;
		const int&			getExecuteGrade() const;
		void				setSign(bool sign);

		void			beSigned(Bureaucrat& b);
		virtual void	execute(Bureaucrat const & executor) const = 0;

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
		class NotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, const AForm &f);

#endif
