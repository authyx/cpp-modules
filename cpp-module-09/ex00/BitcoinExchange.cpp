#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <sstream>
#include <fstream>

BitcoinExchange::BitcoinExchange() {};
BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	data = other.data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		data = other.data;
	}
	return *this;
}

float myStof(const std::string &str)
{
	std::istringstream iss(str);
	float value;
	iss >> value;
	if (iss.fail() || !iss.eof())
	{
		throw std::invalid_argument("Invalid float: " + str);
	}
	return value;
}

std::map<std::string, float> BitcoinExchange::getData() const
{
	return data;
}

void BitcoinExchange::loadData(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		throw std::runtime_error("Could not open file: " + filename);
	}

	std::string line;
	getline(file, line); // Skip header
	while (std::getline(file, line))
	{
		size_t commaPos = line.find(',');
		if (commaPos != std::string::npos)
		{
			std::string date = line.substr(0, commaPos);
			float value = myStof(line.substr(commaPos + 1));
			data[date] = value;
		}
	}
	file.close();
}

bool BitcoinExchange::getValue(const std::string &date, float &value) const
{
	std::map<std::string, float>::const_iterator it = data.find(date);
	if (it != data.end())
	{
		value = it->second;
		return true;
	}

	it = data.upper_bound(date);
	if (it == data.begin())
		return false;

	--it;
	value = it->second;
	return true;
}

int myStoi(const std::string &str)
{
	std::istringstream iss(str);
	int value;
	iss >> value;
	if (iss.fail() || !iss.eof())
	{
		throw std::invalid_argument("Invalid integer: " + str);
	}
	return value;
}
