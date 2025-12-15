#include "Cat.hpp"
#include <iostream>

// Default constructor
Cat::Cat()
{
	std::cout << "Cat created" << std::endl;
	type = "Cat";
	sound = "Meow Meow";
	brain = new Brain();
}

// Copy constructor
Cat::Cat(const Cat& other): AAnimal(other)
{
	type = other.type;
	sound = other.sound;
	brain = new Brain(*other.brain);
}

// Copy assignment operator
Cat& Cat::operator=(const Cat& other)
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
Cat::~Cat()
{
	if (brain)
	{
		delete brain;
		brain = NULL;
	}
	std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat: " << sound << std::endl;
}
