#include "Zombie.hpp"

int main()
{
	Zombie *x = newZombie("bob");
	x->announce();
	randomChump("jim");
	delete x;
	return 0;
}

