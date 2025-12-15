#include "Point.hpp"

// Default constructor
Point::Point() : x(0), y(0)
{
}

Point::Point(const float x_val, const float y_val) : x(x_val), y(y_val)
{
}

// Copy constructor
Point::Point(const Point& other) : x(other.x), y(other.y)
{
}

// Copy assignment operator
Point& Point::operator=(const Point& other)
{
	// Since x and y are const, we cannot assign to them.
	// Therefore, we do nothing here.
	(void)other; // To avoid unused parameter warning
	return *this;
}

// Destructor
Point::~Point()
{
}
