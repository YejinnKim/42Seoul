#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include "utils.hpp"

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secrete;
	public:
		void	SetContact();
		void	GetContact();
		void	GetName(int index);
		void	PrintName(std::string str);
};

#endif
