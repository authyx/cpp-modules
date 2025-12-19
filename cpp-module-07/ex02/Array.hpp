#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <stdexcept>

template <class T>
class Array
{
private:
	T *_elements;
	unsigned int _size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array &other);
	~Array();

	Array &operator=(const Array &other);
	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;

	unsigned int size() const;

	class OutOfBoundsException : public std::exception
	{
		virtual const char* what() const throw();
	};

	void display_elements(void) const;
	void set_element(unsigned int index, T value);
};

#include "Array.tpp"
#endif