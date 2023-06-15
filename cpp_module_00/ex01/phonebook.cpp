#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	index = -1;
	max = false;
}

void	PhoneBook::add()
{
	if (index == 7)
		max = true;
	++index %= 8;
	contacts[index].input_contact();
}

void	PhoneBook::search()
{
	int input;
	int	cnt;

	if (max)
		cnt = 7;
	else
		cnt = index;
	for (int i = 0; i <= cnt; i++)
		contacts[i].print_list(i);
	std::cout << "Enter the index : " << std::endl;
	std::cin >> input;
	if (input >= 0 && input <= cnt)
		contacts[input].print_detail();
}
