#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm():
_name("MyForm"),
_signed(false), _sign_grade(150), _execute_grade(150)
{
}

AForm::AForm(const std::string& name, int signGrade, int executeGrade):
_name(name), _signed(false), _sign_grade(signGrade), _execute_grade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& rhs): _name(rhs._name), _signed(rhs._signed)
, _sign_grade(rhs._sign_grade), _execute_grade(rhs._execute_grade)
{
}

AForm& AForm::operator = (const AForm& rhs)
{
	_signed = rhs._signed;
	return (*this);
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return (_name);
}

bool        AForm::isSigned() const
{
	return (_signed);
}

int   AForm::gradeToSign() const
{
	return (_sign_grade);
}

int   AForm::gradeToExecute() const
{
	return (_execute_grade);
}


void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > (this)->gradeToSign())
	{
		throw AForm::GradeTooLowException();
	}
	_signed = true;
}

std::ostream&  operator << (std::ostream& out, const AForm& rhs)
{
	out << "Name: " << rhs.getName() 
	<< ", Signed: " << std::boolalpha << rhs.isSigned()
	<< ",\nRequired grade to sign: " << rhs.gradeToSign()
	<< ",\nRequired grade to execute: " << rhs.gradeToExecute() 
	<< "\n--------------------------" << std::endl;
	return (out);
}

const char*     AForm::GradeTooHighException::what( ) const throw()
{
	return  ("The grade is too High");
}

const char*     AForm::GradeTooLowException::what( ) const throw()
{
	return  ("The grade is too Low");
}

const char*     AForm::FormNotSignedException::what( ) const throw()
{
	return  ("The form is not signed");
}
