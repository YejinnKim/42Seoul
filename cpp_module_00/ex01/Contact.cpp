#include "Contact.hpp"

void	Contact::SetContact()
{
	first_name = ft_getline("Input first name > ");
	last_name = ft_getline("Input last name > ");
	nickname = ft_getline("Input nickname > ");
	phone_number = ft_getline("Input phone number > ");
	darkest_secrete = ft_getline("Input darkest secrete > ");
}

void	Contact::GetContact()
{
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secrete: " << darkest_secrete << std::endl;
}

void	Contact::GetName(int index)
{
	std::cout << std::right << std::setw(10) << index << " | ";
	PrintName(first_name);
	std::cout << " | ";
	PrintName(last_name);
	std::cout << " | ";
	PrintName(nickname);
	std::cout << std::endl;
}

void	Contact::PrintName(std::string str)
{
	if (str.length() > 10)
		std::cout << std::right << std::setw(10) << str.substr(0, 9) + ".";
	else 
		std::cout << std::right << std::setw(10) << str;
}
