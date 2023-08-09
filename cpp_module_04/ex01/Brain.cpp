#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
	for (int i=0; i < 100; i++)
		ideas[i] = "idea";

}

Brain::Brain(const Brain &ref)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i=0; i < 100; i++)
		ideas[i] = ref.ideas[i];
}

Brain& Brain::operator=(const Brain &ref)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &ref)
	{
		for (int i=0; i < 100; i++)
			ideas[i] = ref.ideas[i];		
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(int i)
{
	return ideas[i];
}

void	Brain::setIdea(std::string idea)
{
	ideas[0] = idea;
}
