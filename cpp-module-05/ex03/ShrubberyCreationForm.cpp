#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

// ========== CONSTRUCTORS ==========

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("default_target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), _target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		this->AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

// ========== MEMBER FUNCTIONS ==========

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!this->isSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->gradeToExecute())
		throw AForm::GradeTooLowException();

	std::ofstream outfile((_target + "_shrubbery").c_str());
	if (!outfile)
	{
		std::cout << "Error: Could not create file " << _target + "_shrubbery" << std::endl;
		return;
	}

	outfile <<
		"       _-_\n"
		"    /~~   ~~\\\n"
		" /~~         ~~\\\n"
		"{               }\n"
		" \\  _-     -_  /\n"
		"   ~  \\\\ //  ~\n"
		"_- -   | | _- _\n"
		"  _ -  | |   -_\n"
		"      // \\\\\n";

	outfile.close();
}

// ========== EXCEPTION CLASSES ==========


// ========== OPERATORS ==========

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& obj)
{
	out << "ShrubberyCreationForm: " << obj.getName() << ", Signed: " << (obj.isSigned() ? "Yes" : "No")
		<< ", Sign Grade: " << obj.gradeToSign() << ", Execute Grade: " << obj.gradeToExecute()
		<< "\n";
	return out;
}