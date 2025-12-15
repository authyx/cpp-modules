#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " \"RPN_EXPRESSION\"" << std::endl;
		return 1;
	}

	RPN rpnCalculator;
	try
	{
		float result = rpnCalculator.evaluate(argv[1]);
		std::cout << result << std::endl;
	}
	catch (...)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	return 0;
}
