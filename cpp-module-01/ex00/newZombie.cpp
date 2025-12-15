#include "Zombie.hpp"

Zombie* newZombie( string name )
{
	Zombie* zombie = new Zombie(name);
	zombie->setName( name );
	return zombie;
}
