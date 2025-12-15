#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <cmath>

// Default constructor
ScalarConverter::ScalarConverter()
{
}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

// Copy assignment operator
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

// Destructor
ScalarConverter::~ScalarConverter()
{
}

void char_converter(std::string str)
{
	if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
	{
		std::cout << "char: '" << str[0] << "'" << std::endl;
	}
	else
	{
		char *endptr;
		long value = std::strtol(str.c_str(), &endptr, 10);
		if (*endptr != '\0' && *endptr != 'f' && *endptr != '.')
		{
			std::cout << "char: impossible" << std::endl;
			return;
		}
		if (value < 0 || value > 127 || !isprint(static_cast<char>(value)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	}
}

void int_converter(std::string str)
{
	char *endptr;
	long value = std::strtol(str.c_str(), &endptr, 10);
	if (*endptr != '\0' && *endptr != 'f' && *endptr != '.')
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	if (value > 2147483647 || value < -2147483648)
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void float_converter(std::string str)
{
	char *endptr;
	float value = std::strtof(str.c_str(), &endptr);
	if (*endptr != '\0' && *endptr != 'f')
	{
		std::cout << "float: impossible" << std::endl;
		return;
	}
	if (value == static_cast<int>(value) && std::fabs(value) < 1000000)
		std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
	else
		std::cout << "float: " << value << "f" << std::endl;
}

void double_converter(std::string str)
{
	char *endptr;
	double value = std::strtod(str.c_str(), &endptr);
	if (*endptr != '\0' && *endptr != 'f')
	{
		std::cout << "double: impossible" << std::endl;
		return;
	}
	if (value == static_cast<int>(value) && std::fabs(value) < 1000000)
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
	else
		std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	if (   str == "nan" || str == "nanf"
		|| str == "+inf" || str == "+inff"
		|| str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (str[str.size() - 1] == 'f')
		{
			std::cout << "float: " << str << std::endl;
			std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
		}
		else
		{
			std::cout << "float: " << str << "f" << std::endl;
			std::cout << "double: " << str << std::endl;
		}
		return;
	}
	char_converter(str);
	int_converter(str);
	float_converter(str);
	double_converter(str);
}