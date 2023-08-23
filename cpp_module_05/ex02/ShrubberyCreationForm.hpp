#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(const ShrubberyCreationForm &ref);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &ref);
		~ShrubberyCreationForm();

		void	execute(Bureaucrat const & executor) const;
};

#endif
