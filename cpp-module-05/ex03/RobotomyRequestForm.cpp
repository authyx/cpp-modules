#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

// ========== CONSTRUCTORS ==========
RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("default_target")
{
	std::srand(std::time(0));
}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::srand(std::time(0));
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), _target(other._target)
{
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		this->AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}
// ========== MEMBER FUNCTIONS ==========
void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!this->isSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->gradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << "Bzzzzzz... Vrrrrrr... *drilling noises*" << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Failed to robotomize " << _target << "." << std::endl;
}
