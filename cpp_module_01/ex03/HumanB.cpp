#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::~HumanB()
{

}

void	HumanB::attack()
{
	std::cout << name << "(" << weapon.getType() << ") attack!!" << std::endl;
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}