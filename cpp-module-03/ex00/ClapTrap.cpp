#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): Name("Default"), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap Default created!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap " << name << " created!" << std::endl;
	Name = name;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap " << copy.Name << " copied!" << std::endl;
	Name = copy.Name;
	hit_points = copy.hit_points;
	energy_points = copy.energy_points;
	attack_damage = copy.attack_damage;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &assign)
{
	std::cout << "ClapTrap " << assign.Name << " assigned!" << std::endl;
	if (this != &assign)
	{
		Name = assign.Name;
		hit_points = assign.hit_points;
		energy_points = assign.energy_points;
		attack_damage = assign.attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << Name << " destroyed!" << std::endl;
	Name = "";
}


void	ClapTrap::attack(const std::string& target)
{
	if (!energy_points || !hit_points)
		return ;
	std::cout << "ClapTrap "
	<< Name
	<< " attacks "
	<< target
	<< ", causing "
	<< attack_damage
	<< " points of damage!"
	<< std::endl;
	energy_points--;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!energy_points || !hit_points)
		return ;
	std::cout
	<< "ClapTrap "
	<< Name
	<< " repairs itself, and regains "
	<< amount
	<< " hit points"
	<< std::endl;
	hit_points += amount;
	energy_points--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!hit_points)
		return ;
	std::cout
	<< "ClapTrap "
	<< Name
	<< " takes "
	<< amount <<
	" points of damage!"
	<< std::endl;
	hit_points -= amount;
}
