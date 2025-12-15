#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}
Intern::~Intern() {}

static AForm* createShrub(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}
static AForm* createRobo(const std::string& target)
{
	return new RobotomyRequestForm(target);
}
static AForm* createPardon(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*creators[3])(const std::string&) = { &createShrub, &createRobo, &createPardon };

	for (int i = 0; i < 3; ++i)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](target);
		}
	}
	std::cout << "Intern couldn't create form: '" << formName << "'" << std::endl;
	return NULL;
}

const char* Intern::UnknownFormException::what() const throw()
{
	return "Intern: unknown form name";
}
