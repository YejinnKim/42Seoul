#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon)
{
	this->name = name;
	this->weapon = weapon;
}

HumanA::~HumanA()
{

}

void	HumanA::attack()
{
	std::cout << name << "(" << weapon.getType() << ") attack!!" << std::endl;
}
