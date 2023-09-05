#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern &ref);
		Intern& operator=(const Intern &ref);
		~Intern();

		AForm*	makeForm(std::string name, std::string target);
		
		class InvalidFormException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif
