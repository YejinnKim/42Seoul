#include "ClapTrap.hpp"

int main()
{
	ClapTrap	a("A");
	ClapTrap	b("B");
	
	a.printStatus();
	b.printStatus();
	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	a.printStatus();
	b.printStatus();
	std::cout << std::endl;

	a.beRepaired(10);
	b.beRepaired(5);
	a.printStatus();
	b.printStatus();
	std::cout << std::endl;

	a.takeDamage(100);
	a.printStatus();
	a.attack("B");
	std::cout << std::endl;

	while (b.getEnergyPoints() > 0)
		b.beRepaired(5);
	b.printStatus();
	b.beRepaired(5);
	std::cout << std::endl;

	return 0;
}
