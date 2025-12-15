#include "Fixed.hpp"

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

int	Fixed::GetFracBits( void )
{
	return fracBits;
}

Fixed &Fixed::operator=(const Fixed &tmp)
{
	this->value = tmp.value;
	return *this;
}

Fixed::Fixed(int n)
{
	std::cout << "Int constructor called" << std::endl;
	value = n << fracBits;
}
Fixed::Fixed(float f)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(f * (1 << fracBits));
}

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed &parent)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = parent;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}