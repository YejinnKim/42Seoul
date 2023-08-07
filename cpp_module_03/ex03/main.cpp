#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap	a("A");
	a.printStatus();
	std::cout << std::endl;

	a.whoAmI();
	std::cout << std::endl;

	a.attack("B");
	std::cout << std::endl;

	return 0;
}
