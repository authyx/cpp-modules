#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main(void)
{
	std::cout << "===== Testing with std::vector =====" << std::endl;
	{
		std::vector<int> vec;
		vec.push_back(10);
		vec.push_back(42);
		vec.push_back(7);
		vec.push_back(99);
		vec.push_back(42);

		try
		{
			std::cout << "Looking for 42..." << std::endl;
			easyfind(vec, 42);
			std::cout << "Found!" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}

		try
		{
			std::cout << "Looking for 100..." << std::endl;
			easyfind(vec, 100);
			std::cout << "Found!" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	return (0);
}
