#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, float> data;

public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);

	void loadData(const std::string &filename);
	std::map<std::string, float> getData() const;
	bool getValue(const std::string &date, float &value) const;
};

float myStof(const std::string &str);
int myStoi(const std::string &str);

#endif