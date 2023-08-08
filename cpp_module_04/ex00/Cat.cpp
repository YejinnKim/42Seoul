#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &ref)
{
	type = ref.type;
}

Cat& Cat::operator=(const Cat &ref)
{
	if (this != &ref)
		type = ref.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "meow!" << std::endl;
}
