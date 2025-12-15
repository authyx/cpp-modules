#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
public:
	void guardGate();

	void attack(const std::string& target);

	ScavTrap(); // added default constructor
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &copy);
	ScavTrap &operator=(const ScavTrap &assign);
	~ScavTrap();

// private:
// 	std::string Name;
// 	int hit_points;
// 	int energy_points;
// 	int attack_damage;
};

#endif // SCAVTRAP_HPP