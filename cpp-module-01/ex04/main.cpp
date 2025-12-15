#include <iostream>
#include <string>
#include <fstream>
#include<cstdlib>

std::string	replace_str(std::string str, std::string old, std::string replace)
{
	std::string	product;
	size_t	r = 0;
	size_t	pos = 0;

	product.reserve(str.length() + replace.length() * 100);
	product = str;
	while (1)
	{
		r = product.find(old, pos);
		if (r == std::string::npos || old.empty() || old == replace)
		{
			return (product);
		}
		product = product.substr(0, r) + replace + product.substr(r + old.length());
		pos = r + pos;
	}
	return (product);
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		return 0;
	}
	std::ifstream from(argv[1]);
	std::string r = argv[1];
	std::string first = argv[2];
	std::string replace = argv[3];
	std::ofstream to ((r + ".replace").c_str());

	if (!from || !to)
	{
		std::cerr << "cannot open a file\n";
		return (1);
	}
	std::string line;
	for (; getline(from, line); )
	{
		line = replace_str(line, first, replace);
		to << line << std::endl;
	}
	return 0;
}
