#include "FragTrap.hpp"

void FragTrap::highFivesGuys()
{
	std::cout
	<< "FragTrap "
	<< Name
	<< " is requesting a high five!"
	<< std::endl;
}

FragTrap::FragTrap(): ClapTrap("Default")
{
	std::cout << "FragTrap constructor called for Default" << std::endl;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called for " << name << std::endl;
	Name = name;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called for " << copy.Name << std::endl;
	Name = copy.Name;
	hit_points = copy.hit_points;
	energy_points = copy.energy_points;
	attack_damage = copy.attack_damage;
}

FragTrap &FragTrap::operator=(const FragTrap &assign)
{
	std::cout << "FragTrap assignment operator called for " << assign.Name << std::endl;
	if (this != &assign)
	{
		Name = assign.Name;
		hit_points = assign.hit_points;
		energy_points = assign.energy_points;
		attack_damage = assign.attack_damage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << Name << std::endl;
}
