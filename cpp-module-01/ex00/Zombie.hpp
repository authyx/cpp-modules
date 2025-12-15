#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

#define cout std::cout 
#define cin std::cin 
#define string std::string 


class Zombie
{
	public:
		void announce( void );
		void setName(string newName);
		string getName(void);
		Zombie( string newName );
		~Zombie();

	private:
		string name;
};

void randomChump( string name );
Zombie* newZombie( string name );

#endif