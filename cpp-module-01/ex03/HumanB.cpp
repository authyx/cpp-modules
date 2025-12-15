#include "HumanB.hpp"

HumanB::HumanB(string Name)
{
	name = Name;
	weapon = NULL;
}

void HumanB::attack()
{
	cout 
	<< name 
	<< " attacks with their "
	<< weapon->getType()
	<< endl;
}

void HumanB::setWeapon(Weapon& new_w)
{
	weapon= &new_w;
}
