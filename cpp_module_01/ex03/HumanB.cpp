#include "HumanB.hpp"

HumanB::HumanB()
{
	
}

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB()
{

}

void	HumanB::attack()
{
	if (weapon)
		std::cout << name << "[" << weapon->getType() << "] attacks!!" << std::endl;
	else
		std::cout << name << " attacks!!" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}