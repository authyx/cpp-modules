#include "Brain.hpp"
#include <iostream>

// Default constructor
Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

// Copy constructor
Brain::Brain(const Brain& other)
{
	// Implementation here
	(void)other;
}

// Copy assignment operator
Brain& Brain::operator=(const Brain& other)
{
	// Implementation here
	(void)other;
	return *this;
}

// Destructor
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
