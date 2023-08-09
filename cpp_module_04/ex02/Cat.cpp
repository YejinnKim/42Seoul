#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &ref)
{
	std::cout << "Cat copy constructor called" << std::endl;
	type = ref.type;
	delete brain;
	brain = new Brain(*ref.brain);
}

Cat& Cat::operator=(const Cat &ref)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		type = ref.type;
		delete brain;
		brain = new Brain(*ref.brain);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void	Cat::makeSound() const
{
	std::cout << "meow!" << std::endl;
}

Brain&	Cat::getBrain() const
{
	return *brain;
}
