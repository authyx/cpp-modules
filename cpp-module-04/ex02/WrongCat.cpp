#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat constructed\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    type = other.type;
    std::cout << "WrongCat copy-constructed\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
        type = other.type;
    std::cout << "WrongCat assigned\n";
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructed\n";
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat: meow (wrong)\n";
}