#include "Animal.hpp"
#include <iostream>

Animal::Animal(): type(""), sound("Generic animal sound")
{
	std::cout << "Animal created" << std::endl;
}

Animal::Animal(const Animal& A): type(A.type), sound(A.sound)
{
	std::cout << "Animal copied" << std::endl;
}

Animal& Animal::operator = (const Animal& org)
{
	std::cout << "Animal assigned" << std::endl;
	if (this != &org)
	{
		this->type = org.type;
		this->sound = org.sound;
	}
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


