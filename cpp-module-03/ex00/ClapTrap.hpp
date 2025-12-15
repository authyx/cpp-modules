#ifndef  CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
private:
	std::string Name;
	int		hit_points;
	int		energy_points;
	int		attack_damage;

public:
	ClapTrap(); // added default constructor

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	ClapTrap &operator=(const ClapTrap &assign);
	~ClapTrap();
};


#endif