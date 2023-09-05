#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(std::string name, std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &ref);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &ref);
		~RobotomyRequestForm();

		void	execute(Bureaucrat const & executor) const;
};

#endif
