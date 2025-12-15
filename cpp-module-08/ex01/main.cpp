#include "Span.hpp"
#include <iostream>

int main()
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		// return 0;
	}
	{
		try
		{
			Span sp = Span(5);
			int numbers[] = {6, 3, 17, 9, 11};
			sp.addRange(numbers, numbers + 5);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(...)
		{
			std::cout << "Exception" << '\n';
		}
	}
	
	return 0;
}