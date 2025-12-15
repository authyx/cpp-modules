#ifndef HD_HPP
#define HD_HPP

#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>


class Contact
{
	public:
		std::string	FirstName;
		std::string	LastName;
		std::string	Nickname;
		std::string	PhoneNumber;
		std::string	DarkestSecret;
	
};

class PhoneBook
{
	public:
		Contact	contacts[8];
		int		id;

};

/* Functions protoypes */

std::string	formatString(std::string s);

#endif