#include "PmergeMe.hpp"
#include <stdexcept>

int main(int argc, char **argv)
{
	PmergeMe P;

	try
	{
		P.parseArgs(argc, argv);
	}
	catch (const std::exception &)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::cout << "Before: ";
	P.printVector();
	
	long tv = micros();
	P.runVectorSort();
	tv = micros() - tv;
	
	long td = micros();
	P.runDequeSort();
	td = micros() - td;
	
	std::cout << "After: ";
	P.printVector();
	
	std::cout << "took std::vector : " << tv << " us" << std::endl;
	std::cout << "took std::deque : " << td << " us" << std::endl;
	return 0;
}