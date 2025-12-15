#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		struct HarlLevels
		{
			std::string level;
			void (Harl::*f)(void);
		};
		
		
	public:
		HarlLevels MyHandler[4];
		void complain( std::string level );
		Harl();
};




#endif