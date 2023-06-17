#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	index = -1;
	max = false;
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::Add()
{
	if (index == 7)
		max = true;
	++index %= 8;
	contacts[index].SetContact();
}

void	PhoneBook::Search()
{
	std::string	input;
	int	index = this->index;

	if (index < 0)
	{
		std::cout << "Phonebook is empty!" << std::endl;
		return ;
	}
	if (max)
		index = 7;
	std::cout << std::right << std::setw(10) << "Index" << " | ";
	std::cout << std::right << std::setw(10) << "First Name" << " | ";
	std::cout << std::right << std::setw(10) << "Last Name" << " | ";
	std::cout << std::right << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i <= index; i++)
		contacts[i].GetName(i);
	
	input = ft_getline("Enter the index > ");
	if (std::cin.eof())
		exit(0);
	if (input.length() == 1 && (input[0] >= '0' && input[0] <= (this->index + '0')))
		contacts[input[0] - '0'].GetContact();
	else
		std::cout << "Invalid index!" << std::endl;
}
