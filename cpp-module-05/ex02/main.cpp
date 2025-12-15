#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"


#include <iostream>

int main(void)
{
	Bureaucrat  bob("Bob", 40);
	ShrubberyCreationForm shrubberyForm("Home");
	RobotomyRequestForm    robotomyForm("Alice");
	PresidentialPardonForm pardonForm("Charlie");

	bob.signForm(shrubberyForm);
	bob.executeForm(shrubberyForm);

	bob.signForm(robotomyForm);
	bob.executeForm(robotomyForm);

	bob.signForm(pardonForm);
	bob.executeForm(pardonForm);

	return 0;
}
