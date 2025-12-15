#include "HumanA.hpp"

HumanA::HumanA(string Name, Weapon& new_weapon) : weapon(new_weapon), name(Name)
{
}

void HumanA::attack()
{
	cout 
	<< name 
	<< " attacks with their "
	<< (weapon).getType()
	<< endl;
}


