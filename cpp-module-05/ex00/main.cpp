#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b;
	std::cout << b;
	try
	{
		b.setGrade(200);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
