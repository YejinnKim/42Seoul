#include "FragTrap.hpp"

int main()
{
	FragTrap	a("A");
	FragTrap	b("B");
	
	a.printStatus();
	b.printStatus();
	std::cout << std::endl;

	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(10);
	a.printStatus();
	b.printStatus();
	std::cout << std::endl;

	a.highFivesGuys();
	std::cout << std::endl;

	return 0;
}
