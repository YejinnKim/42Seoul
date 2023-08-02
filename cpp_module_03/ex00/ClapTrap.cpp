#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{	
	name = "default";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ref)
{
	name = ref.name;
	hitPoints = ref.hitPoints;
	energyPoints = ref.energyPoints;
	attackDamage = ref.attackDamage;
	std::cout << "ClapTrap " << name << " copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &ref)
{
	if (this != &ref)
	{
		name = ref.name;
		hitPoints = ref.hitPoints;
		energyPoints = ref.energyPoints;
		attackDamage = ref.attackDamage;
	}
	std::cout << "ClapTrap " << name << " copy assignment operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destructor called" << std::endl;
}

unsigned int	ClapTrap::getHitPoints()
{
	return hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints()
{
	return energyPoints;
}

unsigned int	ClapTrap::getAttackDamage()
{
	return attackDamage;
}

void	ClapTrap::attack(const std::string& target)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target
			<< ", causing " << attackDamage << " points of damage" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " is died" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints < amount)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << "ClapTrap " << name << " has taken " 
		<< amount << " damage" << std::endl;	
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		hitPoints += amount;
		energyPoints--;
		std::cout << "ClapTrap " << name << " has been repaired of "
				<< amount << " ernergy points" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " is died" << std::endl;
}

void	ClapTrap::printStatus()
{
	std::cout << "ClapTrap " << name << " HP: " << hitPoints 
			<< ", EP: " << energyPoints
			<< ", AD: " << attackDamage << std::endl;
}
