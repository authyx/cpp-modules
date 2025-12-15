#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap{
public:
	void highFivesGuys(void);

	FragTrap(); // added default constructor
	FragTrap(std::string name);
	FragTrap(const FragTrap &copy);
	FragTrap &operator=(const FragTrap &assign);
	~FragTrap();

private:
	// Add members here
};

#endif // FRAGTRAP_HPP