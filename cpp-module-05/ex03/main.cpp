#include "Intern.hpp"
#include "Bureaucrat.hpp"
// The specific forms are still included by Intern.hpp

#include <iostream>

int main()
{
	// A mid-level bureaucrat
	Bureaucrat bob("Bob", 40);

	// The new concept: an Intern that can create forms by name
	Intern intern;

	// Ask the intern to create three forms by string name
	AForm* f1 = intern.makeForm("shrubbery creation", "Home");
	AForm* f2 = intern.makeForm("robotomy request", "Alice");
	AForm* f3 = intern.makeForm("presidential pardon", "Charlie");

	// Also try an unknown one to show error handling
	AForm* bad = intern.makeForm("unknown form", "Nobody");

	// Work with each created form if it exists
	if (f1)
	{
		bob.signForm(*f1);
		bob.executeForm(*f1);
	}
	if (f2)
	{
		bob.signForm(*f2);
		bob.executeForm(*f2);
	}
	if (f3)
	{
		bob.signForm(*f3);
		bob.executeForm(*f3);
	}

	// Clean up allocated forms
	delete f1;
	delete f2;
	delete f3;
	// bad is NULL when creation fails
	(void)bad;

	return 0;
}
