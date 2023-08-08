#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &ref)
{
	type = ref.type;
}

WrongCat& WrongCat::operator=(const WrongCat &ref)
{
	if (this != &ref)
		type = ref.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "meow!" << std::endl;
}
