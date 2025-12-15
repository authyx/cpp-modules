#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

int	getComplaining(std::string level, Harl::HarlLevels *MyHandler);

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		
		
	public:
		struct HarlLevels
		{
			std::string level;
			void (Harl::*f)(void);
		};
		HarlLevels MyHandler[4];
		void complain( std::string level );
		Harl();
};




#endif