#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <limits>

std::string trim(const std::string &str)
{
	size_t start = 0;
	size_t end = str.length();

	while (start < end && std::isspace(str[start]))
		start++;
	while (end > start && std::isspace(str[end - 1]))
		end--;

	return str.substr(start, end - start);
}

bool isValidDate(const std::string &date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year, month, day;
	try
	{
		year = myStoi(date.substr(0, 4));
		month = myStoi(date.substr(5, 2));
		day = myStoi(date.substr(8, 2));
	}
	catch (...)
	{
		std::cerr << "Error: Invalid date format." << std::endl;
		return false;
	}

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;

	if (month == 2)
	{
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > (isLeap ? 29 : 28))
			return false;
	}
	return true;
}

void processData(std::ifstream &inputFile, const BitcoinExchange &btcExchange)
{
	std::string date;
	std::string valueStr;
	std::string line;
	size_t delPos;
	float amount;
	getline(inputFile, line); // Skip header

	while (getline(inputFile, line))
	{
		delPos = line.find('|');
		if (delPos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		date = trim(line.substr(0, delPos));
		valueStr = trim(line.substr(delPos + 1));

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		try
		{
			amount = myStof(valueStr);
		}
		catch (const std::invalid_argument &e)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (amount < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}

		if (amount > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		float rate = 0.0f;
		if (!btcExchange.getValue(date, rate))
		{
			std::cerr << "Error: date too early." << std::endl;
			continue;
		}

		std::cout << date << " => " << amount << " = " << (amount * rate) << std::endl;
	}
}

int main(int argc, char **argv)
{
	BitcoinExchange btcExchange;
	if (argc != 3)
	{
		std::cerr << "Error: Wrong number of arguments." << std::endl;
		return 1;
	}
	try
	{
		btcExchange.loadData(argv[2]);
		std::ifstream inputFile(argv[1]);
		if (!inputFile.is_open())
		{
			throw std::runtime_error("Error: Could not open input file.");
		}
		processData(inputFile, btcExchange);
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}