#include "Fixed.hpp"

float Fixed::toFloat( void ) const
{
	return roundf(value) / (1 << fracBits);
}

int Fixed::toInt( void ) const
{
	return getRawBits() >> fracBits;
}

std::ostream& operator << (std::ostream& out, const Fixed& tmp)
{
	return (out << tmp.toFloat());
}
