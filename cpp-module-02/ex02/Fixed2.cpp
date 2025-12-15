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

bool operator > (Fixed& C1, Fixed& C2)
{
	return (C1.getRawBits() > C2.getRawBits());
}
bool operator < (Fixed& C1, Fixed& C2)
{
	return (C1.getRawBits() < C2.getRawBits());
}
bool operator >= (Fixed& C1, Fixed& C2)
{
	return (C1.getRawBits() >= C2.getRawBits());
}
bool operator <= (Fixed& C1, Fixed& C2)
{
	return (C1.getRawBits() <= C2.getRawBits());
}
bool operator == (Fixed& C1, Fixed& C2)
{
	return (C1.getRawBits() == C2.getRawBits());
}
bool operator != (Fixed& C1, Fixed& C2)
{
	return (C1.getRawBits() != C2.getRawBits());
}

Fixed		Fixed::operator + ( Fixed& C1)
{
	Fixed result;
	result.setRawBits((*this).getRawBits() + C1.getRawBits());
	return (result);
}

Fixed		Fixed::operator - ( Fixed& C1)
{
	Fixed result;
	result.setRawBits((*this).getRawBits() - C1.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result.value = (long)(this->value * other.value) / (1 << fracBits);
	return result;
}

Fixed		Fixed::operator / (const Fixed& C1) const
{
	Fixed result;
	result.value = ((this->value * (1 << fracBits)) / C1.value) ;
	return result;
}

Fixed		Fixed::operator ++ ()
{
	value += 1;
	return (*this);
	
}

Fixed		Fixed::operator -- ()
{
	Fixed tmp (*this);
	value -= 1;
	return (tmp);
}

Fixed		Fixed::operator ++ (int)
{
	Fixed tmp (*this);
	value += 1;
	return (tmp);
}

Fixed		Fixed::operator -- (int)
{
	value -= 1;
	return (*this);
}

Fixed	Fixed::max(const Fixed& A, const Fixed& B)
{
	if (A.getRawBits() > B.getRawBits())
		return A;
	else
		return B;
}

Fixed	Fixed::min(const Fixed& A, const Fixed& B)
{
	if (A.getRawBits() < B.getRawBits())
		return A;
	else
		return B;
}
