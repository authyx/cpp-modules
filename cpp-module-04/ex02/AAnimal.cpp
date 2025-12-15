#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal()
{
	std::cout << "AAnimal created" << std::endl;
	type = "";
	sound = "Generic animal sound";
}
AAnimal::AAnimal(const AAnimal& A)
{
	std::cout << "AAnimal copied" << std::endl;
	type = A.type;
}
AAnimal& AAnimal::operator = (const AAnimal& org)
{
	std::cout << "AAnimal assigned" << std::endl;
	this->type = org.type;
	this->sound = org.sound;
	return *this;
}
AAnimal::~AAnimal()
{
	std::cout << "AAnimal destroyed" << std::endl;
}

// ########################################################################

std::string AAnimal::getType() const
{
	return (type);
}


