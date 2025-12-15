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
	int	GetFracBits();
	void setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;

	Fixed();
	Fixed ( int n );
	Fixed( float f);
	Fixed(const Fixed & parent);
	

	Fixed& operator= ( const Fixed &tmp);

	// Arithmetic
	Fixed		operator + ( Fixed& C1 );
	Fixed		operator*(const Fixed& other) const;
	Fixed		operator - ( Fixed& C1 );
	Fixed		operator / ( const Fixed& C1 ) const;

	// Pre operations
	Fixed		operator ++ ();
	Fixed		operator -- ();

	// Post operations
	Fixed	operator ++ (int);
	Fixed	operator -- (int);

	static Fixed	max(const Fixed& A, const Fixed& B);
	static Fixed	min(const Fixed& A, const Fixed& B);
	
	~Fixed();
};

// to stream out
std::ostream& operator<< (std::ostream& out, const Fixed& tmp);

// Comparison

bool	operator > (const Fixed& C1, const Fixed& C2);
bool	operator < (const Fixed& C1, const Fixed& C2);
bool	operator >= (const Fixed& C1, const Fixed& C2);
bool	operator <= (const Fixed& C1, const Fixed& C2);
bool	operator == (const Fixed& C1, const Fixed& C2);
bool	operator != (const Fixed& C1, const Fixed& C2);

#endif