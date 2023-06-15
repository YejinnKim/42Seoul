#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		index;
		bool	max;
	public:
		PhoneBook();
		void	add();
		void	search();
};

#endif