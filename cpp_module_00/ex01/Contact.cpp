#include <iomanip>
#include "Contact.hpp"

void	Contact::input_contact()
{
	std::cout << "Input first name : " << std::endl;
	std::cin >> first_name;
	std::cout << "Input last name : " << std::endl;
	std::cin >> last_name;
	std::cout << "Input nickname : " << std::endl;
	std::cin >> nickname;
	std::cout << "Input phone number : " << std::endl;
	std::cin >> phone_number;
	std::cout << "Input darkest secrete : " << std::endl;
	std::cin >> darkest_secrete;
}

void	print_str(std::string str)
{
	if (str.length() > 10)
		std::cout << std::right << std::setw(10) << str.substr(0, 9) + ".";
	else 
		std::cout << std::right << std::setw(10) << str;
}

void	Contact::print_list(int index)
{
	std::cout << index << " | ";
	print_str(first_name);
	std::cout << " | ";
	print_str(last_name);
	std::cout << " | ";
	print_str(nickname);
	std::cout << std::endl;
}

void	Contact::print_detail()
{
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secrete: " << darkest_secrete << std::endl;
}