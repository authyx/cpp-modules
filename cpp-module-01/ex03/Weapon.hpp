#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

#define cout std::cout 
#define cin std::cin 
#define string std::string 
#define endl std::endl 


class Weapon
{
private:
	string type;
public:
	Weapon(string Type);
	string& getType()
	{
		return (string &)type;
	};
	void setType(string str);
};




#endif