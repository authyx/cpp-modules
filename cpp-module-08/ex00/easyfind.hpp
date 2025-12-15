#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>

class NotFoundException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return ("Not found");
	};
};

template <typename T>
typename T::iterator easyfind(T &container, int element)
{
	typename T::iterator it = std::find(container.begin(), container.end(), element);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

#endif