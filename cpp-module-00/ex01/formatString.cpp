#include "hd.hpp"

std::string	formatString(std::string s)
{
	std::string new_s;
	if (s.length() >= 10)
	{
		for (int i = 0; i < 9 ; ++i)
		{
			new_s += s[i];
		}
		new_s += '.';
	}
	else
	{
		for (int i = 0; i + s.length() < 10 ; i++)
		{
			new_s += ' ';
		}
		// std::cout << "new:{" << new_s << "}\n";
		new_s += s;
	}
	return (new_s);
}
