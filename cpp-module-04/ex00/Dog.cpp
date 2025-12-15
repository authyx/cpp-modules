#include "Dog.hpp"
#include <iostream>

// Default constructor
Dog::Dog()
{
	std::cout << "Dog created" << std::endl;
	type = "Dog";
	sound = "Woof Woof";
}

// Copy constructor
Dog::Dog(const Dog& other): Animal(other)
{
	type = other.type;
	sound = other.sound;
}

// Copy assignment operator
Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		type = other.type;
		sound = other.sound;
	}
	return *this;
}

// Destructor
Dog::~Dog()
{
	std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Animal is making a sound: " << sound << std::endl;
}
