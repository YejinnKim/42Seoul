#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(std::string name, std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &ref);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &ref);
		~PresidentialPardonForm();

		void	execute(Bureaucrat const & executor) const;
};

#endif
