#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
	ShrubberyCreationForm();

public:
	// Orthodox Canonical Form
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	// Parameterized constructor
	ShrubberyCreationForm(const std::string& target);

	// Execute function (pure virtual implementation)
	void execute(Bureaucrat const& executor) const;
};

#endif