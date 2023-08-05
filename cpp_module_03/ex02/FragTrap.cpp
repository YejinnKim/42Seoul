#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	name = "default";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ref)
{
	name = ref.name;
	hitPoints = ref.hitPoints;
	energyPoints = ref.energyPoints;
	attackDamage = ref.attackDamage;
	std::cout << "FragTrap " << name << " copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &ref)
{
	if (this != &ref)
	{
		name = ref.name;
		hitPoints = ref.hitPoints;
		energyPoints = ref.energyPoints;
		attackDamage = ref.attackDamage;
	}
	std::cout << "FragTrap " << name << " copy assignment operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " requests a high five." << std::endl;
}
