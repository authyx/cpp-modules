#include "hd.hpp"
#include <cstdlib>

void	put_msg(std::string s)
{
	std::cout << s << "\n";
}

std::string	get_feild()
{
	std::string s;

	std::cin >> s;
	if (!std::cin)
	{
		std::cout << "Error" << "\n";
		exit(EXIT_FAILURE);
	}
	return (s);
}

void	add(PhoneBook *phonebook)
{
	int id;

	id = phonebook->id;
	phonebook->id++;
	put_msg("Enter the first name");
	(phonebook)->contacts[id % 8].FirstName = get_feild();
	put_msg("Enter the last name");
	(phonebook)->contacts[id % 8].LastName = get_feild();
	put_msg("Enter the nickname");
	(phonebook)->contacts[id % 8].Nickname = get_feild();
	put_msg("Enter the phone number");
	(phonebook)->contacts[id % 8].PhoneNumber = get_feild();
	put_msg("Enter the darkest secret");
	(phonebook)->contacts[id % 8].DarkestSecret = get_feild();
	if (id % 8 == 7)
		phonebook->id = 0;
}

std::string repeatString(const std::string& str, int times)
{
	std::string result;
	for (int i = 0; i < times; ++i)
	{
		result += str;
	}
	return result;
}

void	printContact(Contact contact, int i)
{
	std::string formated;
	std::string tmp;
	int len;
	
	std::cout << "          " << i << "|";
	formated = formatString(contact.FirstName);
	len = formated.length();
	std::cout << formated << "|";
	formated = formatString(contact.LastName);
	len = formated.length();
	std::cout << formated << "|";
	formated = formatString(contact.Nickname);
	len = formated.length();
	std::cout << formated << "|";
}

void	border_row()
{
	std::cout << "\n";
	for (int j = 46; j > 0; j--)
	{
		if (j == 46 || j == 1)
			std::cout << "+";
		else
			std::cout << "-";
	}
}

void	search(PhoneBook phonebook)
{
	int max = 8;
	int i = max;
	int max_len = 0;

	while (i--)
	{
		if (phonebook.contacts[i].Nickname.length() > max_len)
			max_len = phonebook.contacts[i].Nickname.length();
		if (phonebook.contacts[i].LastName.length() > max_len)
			max_len = phonebook.contacts[i].LastName.length();
		if (phonebook.contacts[i].FirstName.length() > max_len)
			max_len = phonebook.contacts[i].FirstName.length();
	}
	border_row();
	i = 0;
	while (i < max)
	{
		std::cout << "\n|";
		printContact(phonebook.contacts[i], i);
		i++;
	}
	border_row();
}

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"

int	main()
{
	PhoneBook phonebook;
	std::string s;
	phonebook.id = 0;
	while (1)
	{
		std::cout << GREEN "\n+----Welcome to the PhoneBook----+\n" RESET;
		std::cout << CYAN "Please enter a command\n" RESET;
		std::cout << "You can use the following commands:\n";
		std::cout << YELLOW "ADD\t" RESET ": Add a new contact\n";
		std::cout << YELLOW "SEARCH\t" RESET ": Search for a contact\n";
		std::cout << YELLOW "EXIT\t" RESET ": Exit the program\n";
		std::cout << GREEN "----------------------------------\n" RESET;
		std::cout << "Enter command: " RESET;
		std::cin >> s;
		if (std::cin.eof())
		{
			std::cout << RED "\nError" RED << "\n";
			exit(EXIT_FAILURE);
		}
		// system("clear");
		if (s == "ADD" || s == "A")
		{
			add(&phonebook);
		}
		else if (s == "SEARCH" || s == "S")
		{
			search(phonebook);
		}
		else if (s == "EXIT" || s == "E")
		{
			std::cout << "See you later" << "\n";
			exit(EXIT_SUCCESS);
		}
		std::cout << "\n";
	}
	
}
