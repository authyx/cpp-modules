#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
#include <string>
#include <iostream>
class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
	PresidentialPardonForm();
public:
	// Orthodox Canonical Form
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();
	// Parameterized constructor
	PresidentialPardonForm(const std::string& target);
	// Execute function (pure virtual implementation)
	void execute(Bureaucrat const& executor) const;
};
#endif