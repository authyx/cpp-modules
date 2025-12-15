#include "Dog.hpp"
#include <iostream>

// Default constructor
Dog::Dog()
{
	std::cout << "Dog created" << std::endl;
	type = "Dog";
	sound = "Woof Woof";
	brain = new Brain();
}

// Copy constructor
Dog::Dog(const Dog& other): AAnimal(other)
{
	type = other.type;
	sound = other.sound;
	brain = new Brain(*other.brain);
}

// Copy assignment operator
Dog& Dog::operator=(const Dog& other)
{
	type = other.type;
	sound = other.sound;
	if (brain)
	{
		delete brain;
		brain = NULL;
	}
	brain = new Brain(*other.brain);
	return *this;
}

// Destructor
Dog::~Dog()
{
	if (brain)
	{
		delete brain;
		brain = NULL;
	}
	std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog: " << sound << std::endl;
}
