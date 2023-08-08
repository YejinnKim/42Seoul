#include "Animal.hpp"

Animal::Animal()
{
	type = "";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &ref)
{
	type = ref.type;
}

Animal& Animal::operator=(const Animal &ref)
{
	if (this != &ref)
		type = ref.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType() const
{
	return type;
}

void	Animal::makeSound() const
{
	std::cout << "No sound!" << std::endl;
}
