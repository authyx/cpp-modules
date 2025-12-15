#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include "HumanA.hpp"
class HumanB
{
	private:
		Weapon *weapon;
		string name;
	public:
		HumanB(string Name);
		void attack();
		void setWeapon(Weapon& new_w);

};

#endif