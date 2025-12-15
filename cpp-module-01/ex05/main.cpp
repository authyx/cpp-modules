#include "Harl.hpp"


int main(int argc, char const *argv[])
{
	Harl harl;

	harl.complain("debug");
	harl.complain("failed");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("error");
	(void) argc;
	(void) argv;
	return 0;
}
