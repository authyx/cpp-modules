#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <exception>
#include <iostream>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	// Orthodox Canonical Form
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* makeForm(const std::string& formName, const std::string& target) const;

	class UnknownFormException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif
