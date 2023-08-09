#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
	type = "";
}

Animal::Animal(const Animal &ref)
{
	std::cout << "Animal copy constructor called" << std::endl;
	type = ref.type;
}

Animal& Animal::operator=(const Animal &ref)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
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
