#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	name;
		bool				sign;
		const int			signGrade;
		const int			executeGrade;
	protected:
		void	setName(const std::string &name);
		void	setSign(bool sign);
		void	setSignGrade(int signGrade);
		void	setExecuteGrade(int executeGrade);
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

		void			beSigned(const Bureaucrat& b);
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
