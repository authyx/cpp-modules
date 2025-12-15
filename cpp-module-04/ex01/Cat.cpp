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
Cat::Cat(const Cat& other): Animal(other)
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

void Cat::setIdea(int idx, const std::string& idea)
{
	if (idx >= 0 && idx < 100 && brain)
		brain->ideas[idx] = idea;
}

std::string Cat::getIdea(int idx) const
{
	if (idx >= 0 && idx < 100 && brain)
		return brain->ideas[idx];
	return std::string();
}
