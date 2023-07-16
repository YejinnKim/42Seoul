#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{

}

HumanA::~HumanA()
{

}

void HumanA::attack()
{
	std::cout << name << "[" << weapon.getType() << "] attacks!!" << std::endl;
}
