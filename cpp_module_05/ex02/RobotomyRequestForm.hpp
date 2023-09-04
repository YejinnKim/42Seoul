#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(const RobotomyRequestForm &ref);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &ref);
		~RobotomyRequestForm();

		void	execute(Bureaucrat const & executor) const;
};

#endif
