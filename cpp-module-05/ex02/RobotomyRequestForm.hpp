#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <string>
#include <iostream>
class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
	RobotomyRequestForm();
public:
	// Orthodox Canonical Form
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();
	// Parameterized constructor
	RobotomyRequestForm(const std::string& target);
	// Execute function (pure virtual implementation)
	void execute(Bureaucrat const& executor) const;
};
#endif
