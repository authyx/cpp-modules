#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	try
	{
		// Test with default constructors
		Bureaucrat	b1;
		Form		f1;
		std::cout << "=== Testing Default Objects ===" << std::endl;
		std::cout << f1;
		std::cout << b1;
		
		std::cout << "\n=== Testing Signing (Should Fail) ===" << std::endl;
		b1.signForm(f1);

		std::cout << "\n=== Testing Parameterized Objects ===" << std::endl;
		Bureaucrat	b2("John", 50);
		Form		f2("TaxForm", 60, 40);
		std::cout << f2;
		std::cout << b2;
		
		std::cout << "\n=== Testing Successful Signing ===" << std::endl;
		b2.signForm(f2);
		std::cout << "After signing:\n" << f2;
		
		std::cout << "\n=== Testing Insufficient Grade ===" << std::endl;
		Bureaucrat	b3("Bob", 80);
		Form		f3("ImportantForm", 70, 50);
		b3.signForm(f3);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	return 0;
}
