#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Clap ("Boss");
	Clap.attack("Nerd");
	Clap.beRepaired(5);
	Clap.takeDamage(3);
	return 0;
}

