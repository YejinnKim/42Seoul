#include "ScavTrap.hpp"

int main()
{
	ScavTrap	a("A");
	ScavTrap	b("B");
	
	a.printStatus();
	b.printStatus();
	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(10);
	a.printStatus();
	b.printStatus();
	std::cout << std::endl;

	a.guardGate();
	std::cout << std::endl;

	return 0;
}
