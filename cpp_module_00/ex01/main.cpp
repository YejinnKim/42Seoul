#include "Contact.hpp"
#include "PhoneBook.hpp"

// p150. 정보 은닉
int main()
{
	PhoneBook	phonebook;
	std::string	cmd;

	while (1)
	{
		std::cout << "Enter the command (ADD, SEARCH, EXIT) : " << std::endl;
		std::cin >> cmd;
		if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
		else if (cmd == "EXIT")
			break;
	}
	return (0);
}