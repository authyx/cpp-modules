#include "iter.hpp"

void printChar(const char &c)
{
	std::cout << c << std::endl;
}

void increment(const int &n) {
	std::cout << n + 1 << std::endl;
}

int main()
{
	char arrayChar[] = {'a', 'b', 'c', 'd', 'e'};
	::iter(arrayChar, 5, &printChar);

	const  int carr[] = {4, 5, 6};
	::iter(carr, 3, &increment);
	return 0;
}