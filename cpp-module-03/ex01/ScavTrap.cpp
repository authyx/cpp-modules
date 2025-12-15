#include "ScavTrap.hpp"

void ScavTrap::guardGate()
{
	std::cout
	<< "ScavTrap "
	<< Name
	<< " is now in Gatekeeper mode."
	<< std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (!energy_points || !hit_points)
		return;
	std::cout
	<< "ScavTrap "
	<< Name
	<< " attacks "
	<< target
	<< ", causing "
	<< attack_damage
	<< " points of damage!"
	<< std::endl;
	energy_points--;
}

ScavTrap::ScavTrap(): ClapTrap("Default")
{
	std::cout << "ScavTrap " << Name << " created." << std::endl;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << Name << " created." << std::endl;
	Name = name;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap " << copy.Name << " copied." << std::endl;
	Name = copy.Name;
	hit_points = copy.hit_points;
	energy_points = copy.energy_points;
	attack_damage = copy.attack_damage;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &assign)
{
	std::cout << "ScavTrap " << assign.Name << " assigned." << std::endl;
	if (this != &assign)
	{
		Name = assign.Name;
		hit_points = assign.hit_points;
		energy_points = assign.energy_points;
		attack_damage = assign.attack_damage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap" << Name << " destroyed." << std::endl;
}