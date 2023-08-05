#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	name = "default";
	hitPoints = 0;
	energyPoints = 0;
	attackDamage = 0;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->name = name;
	hitPoints = 0;
	energyPoints = 0;
	attackDamage = 0;
	std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref)
{
	name = ref.name;
	hitPoints = ref.hitPoints;
	energyPoints = ref.energyPoints;
	attackDamage = ref.attackDamage;
	std::cout << "DiamondTrap " << name << " copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &ref)
{
	if (this != &ref)
	{
		name = ref.name;
		hitPoints = ref.hitPoints;
		energyPoints = ref.energyPoints;
		attackDamage = ref.attackDamage;
	}
	std::cout << "DiamondTrap " << name << " copy assignment operator called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " destructor called" << std::endl;
}

void	DiamondTrap::whoAmI()
{

}
