#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string ft_getline(std::string str)
{
	std::string cmd;

	std::cout << str << std::endl;
	std::getline(std::cin, cmd);
	if (std::cin.eof())
		exit(0);
	return (cmd);
}

// p150. 정보 은닉
int main()
{
	PhoneBook	phonebook;
	std::string	cmd;

	while (1)
	{
		cmd = ft_getline("Enter the command (ADD, SEARCH, EXIT) > ");
		if (cmd == "ADD")
			phonebook.Add();
		else if (cmd == "SEARCH")
			phonebook.Search();
		else if (cmd == "EXIT")
			break;
		else
			std::cout << "Invalid command!" << std::endl;
	}
	return (0);
}