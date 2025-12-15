#include "Zombie.hpp"

Zombie::~Zombie()
{
	cout << "deleting.." << name << std::endl;
	// what to delete
}

Zombie::Zombie(string newName)
{
	name = newName;
	cout << "Creating a new Zombie" << std::endl;
	return;
}

void Zombie::setName(string newName)
{
	name = newName;
}
string Zombie::getName(void)
{
	return ( name );
}

void Zombie::announce( void )
{
	cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
