#include "Zombie.hpp"

int main()
{
	int n = 5;
	Zombie *zombies = zombieHorde(n, "zombie");
	
	for (int i = 0; i < n; i++)
		zombies[i].announce();
	delete [] zombies;
	return (0);
}
