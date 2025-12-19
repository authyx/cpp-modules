#include "Array.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	Array<int> MyArray;
	std::cout << "Size of MyArray: " << MyArray.size() << std::endl;
	Array<int> IntArray(10);
	std::cout << "Size of IntArray: " << IntArray.size() << std::endl;
	srand(static_cast<unsigned int>(time(0)));
	for (unsigned int i = 0; i < IntArray.size(); i++)
	{
		IntArray.set_element(i, rand() % 100);
	}
	IntArray.display_elements();
	try
	{
		std::cout << "Accessing out-of-bounds index 10:" << std::endl;
		std::cout << IntArray[10] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
