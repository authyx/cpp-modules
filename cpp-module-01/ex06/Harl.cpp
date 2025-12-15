#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
}
void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
}
void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
}
void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
}

Harl::Harl()
{
	MyHandler[0] = (HarlLevels) {"debug", &Harl::debug};
	MyHandler[1] = (HarlLevels) {"info", &Harl::info};
	MyHandler[2] = (HarlLevels) {"warning", &Harl::warning};
	MyHandler[3] = (HarlLevels) {"error", &Harl::error};
}

int	getComplaining(std::string level, Harl::HarlLevels *MyHandler)
{
	int i = -1;
	for (int j = 0; j < 4; j++)
	{
		if (level == MyHandler[j].level)
			i = j;
	}
	switch (i)
	{
	case -1:
		std::cout << "[ Probably complaining about insignificant problems ]"
		<< std::endl;
		return 4;
		break ;
	default:
		return i;
	}
}

void Harl::complain( std::string level )
{
	for (int i = getComplaining(level, MyHandler); i < 4; i++)
	{
		(this->*MyHandler[i].f)();
	}
}
