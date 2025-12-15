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

void Harl::complain( std::string level )
{
	int i = 0;
	for (; i < 4 && MyHandler[i].level != level; i++);
	if (i == 4)
		return ;
	(this->*MyHandler[i].f)();
}
