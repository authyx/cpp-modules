#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
// ========== CONSTRUCTORS ==========

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("default_target")
{
}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), _target(other._target)
{
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		this->AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
}
// ========== MEMBER FUNCTIONS ==========
void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (!this->isSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->gradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}