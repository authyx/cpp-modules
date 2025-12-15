#include "Zombie.hpp"
#include <stdlib.h>

int main(int ac, char **av)
{
	int N = 1;
	string name = "bob";
	if (ac > 1)
	{
		N = atoi(av[1]);
	}

	Zombie *x = zombieHorde(N, name);
	delete[] x;
	return 0;
}

