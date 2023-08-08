#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &ref)
{
	type = ref.type;
}

Dog& Dog::operator=(const Dog &ref)
{
	if (this != &ref)
		type = ref.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "bark bark!" << std::endl;
}
