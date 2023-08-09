#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &ref)
{
	std::cout << "Dog copy constructor called" << std::endl;
	type = ref.type;
	delete brain;
	brain = new Brain(*ref.brain);
}

Dog& Dog::operator=(const Dog &ref)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		type = ref.type;
		delete brain;
		brain = new Brain(*ref.brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void	Dog::makeSound() const
{
	std::cout << "bark bark!" << std::endl;
}

Brain&	Dog::getBrain() const
{
	return *brain;
}
