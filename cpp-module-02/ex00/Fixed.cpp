#include "Fixed.hpp"

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

Fixed& Fixed::operator= ( Fixed& test)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = test.value;
	return *this;
}

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(Fixed & parent)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = parent.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}