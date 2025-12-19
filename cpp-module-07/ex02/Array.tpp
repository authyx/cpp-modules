
template <class T>
class Array;

// OCF
template <class T>
Array<T>::Array() : _elements(new T[1]()), _size(1)
{
}

template <class T>
Array<T>::Array(unsigned int n): _elements(NULL), _size(0)
{
	if (_size != 0)
		delete[] _elements;
	_elements = new T[n]();
	_size = n;
}

template <class T>
Array<T>::Array(const Array &other)
{
	_size = other.size();
	_elements = new T[other.size()]();
	for (unsigned int i = 0; i < _size; i++)
		_elements[i] = T(other._elements[i]);
}

template <class T>
Array<T>::~Array()
{
	delete[] _elements;
}

// Exception what() implementation
template <class T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return "Array index out of bounds";
}

// Operator overloads
template <class T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] _elements;
		_size = other.size();
		_elements = new T[_size]();
		for (unsigned int i = 0; i < _size; i++)
			_elements[i] = T(other._elements[i]);
	}
	return *this;
}

template <class T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _elements[index];
}

template <class T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _elements[index];
}

// Utility functions

template <class T>
void Array<T>::display_elements() const
{
	std::cout << "First element: " << _elements[0] << std::endl;
}

template <class T>
void Array<T>::set_element(unsigned int index, T value)
{
	if (index >= _size)
		throw OutOfBoundsException();
	_elements[index] = value;
}

template <class T>
unsigned int Array<T>::size() const
{
	return _size;
}