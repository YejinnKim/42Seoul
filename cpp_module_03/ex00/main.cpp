#include "ClapTrap.hpp"

int main()
{
	ClapTrap	a("A");
	ClapTrap	b("B");
	
	std::cout << std::endl;
	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	a.printStatus();
	b.printStatus();
	std::cout << std::endl;

	a.beRepaired(3);
	b.beRepaired(5);
	a.printStatus();
	b.printStatus();
	std::cout << std::endl;

	while (a.getEnergyPoints() > 0)
		a.beRepaired(5);
	a.printStatus();
	a.beRepaired(5);
	std::cout << std::endl;

	return 0;
}