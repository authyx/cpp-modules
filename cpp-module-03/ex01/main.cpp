#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap Clap ("Smash");
	Clap.guardGate();
	Clap.attack("Nerd");
	Clap.beRepaired(5);
	Clap.takeDamage(3);
	return 0;
}

