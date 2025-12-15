#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int	value;
	static const int fracBits = 8;
public:
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	Fixed();
	Fixed(Fixed & parent);
	Fixed & operator= ( Fixed& test);
	~Fixed();
};

#endif