#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"


class Point
{
	private:
		Fixed const x;
		Fixed const y;
	public:
		// Default constructor
		Point();
		Point(const float x_val, const float y_val);
		
		// Copy constructor
		Point(const Point& other);
		
		// Copy assignment operator
		Point& operator=(const Point& other);
		
		// Destructor
		~Point();
};

#endif