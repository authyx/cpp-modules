#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "Animal created" << std::endl;
	type = "";
	sound = "Generic animal sound";
}
Animal::Animal(const Animal& A)
{
	std::cout << "Animal copied" << std::endl;
	type = A.type;
}
Animal& Animal::operator = (const Animal& org)
{
	std::cout << "Animal assigned" << std::endl;
	this->type = org.type;
	this->sound = org.sound;
	return *this;
}
Animal::~Animal()
{
	std::cout << "Animal destroyed" << std::endl;
}

// ########################################################################

void Animal::makeSound() const
{
	std::cout << "Animal is making a sound: " << sound << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}


