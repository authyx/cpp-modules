#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	value;
	static const int fracBits = 8;
public:
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;

	Fixed();
	Fixed ( int n );
	Fixed( float f);
	Fixed(const Fixed & parent);

	Fixed& operator= ( const Fixed &tmp);
	~Fixed();
};

std::ostream& operator<< (std::ostream& out, const Fixed& tmp);


#endif