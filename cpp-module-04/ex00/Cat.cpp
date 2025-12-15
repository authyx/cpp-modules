#include "Cat.hpp"
#include <iostream>

// Default constructor
Cat::Cat()
{
	std::cout << "Cat created" << std::endl;
	type = "Cat";
	sound = "Meow Meow";
}

// Copy constructor
Cat::Cat(const Cat& other): Animal(other)
{
	type = other.type;
	sound = other.sound;
}

// Copy assignment operator
Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		type = other.type;
		sound = other.sound;
	}
	return *this;
}

// Destructor
Cat::~Cat()
{
	std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Animal is making a sound: " << sound << std::endl;
}
