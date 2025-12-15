#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form():
_name("MyForm"),
_signed(false), _sign_grade(150), _execute_grade(150)
{
}

Form::Form(const std::string& name, int signGrade, int executeGrade):
_name(name), _signed(false), _sign_grade(signGrade), _execute_grade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& rhs): _name(rhs._name), _signed(rhs._signed)
, _sign_grade(rhs._sign_grade), _execute_grade(rhs._execute_grade)
{
}

Form& Form::operator = (const Form& rhs)
{
	_signed = rhs._signed;
	return (*this);
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return (_name);
}

bool        Form::isSigned() const
{
	return (_signed);
}

int   Form::gradeToSign() const
{
	return (_sign_grade);
}

int   Form::gradeToExecute() const
{
	return (_execute_grade);
}


void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > (this)->gradeToSign())
	{
		throw Form::GradeTooLowException();
	}
	_signed = true;
}

std::ostream&  operator << (std::ostream& out, const Form& rhs)
{
	out << "Name: " << rhs.getName() 
	<< ", Signed: " << std::boolalpha << rhs.isSigned()
	<< ",\nRequired grade to sign: " << rhs.gradeToSign()
	<< ",\nRequired grade to execute: " << rhs.gradeToExecute() 
	<< "\n--------------------------" << std::endl;
	return (out);
}

const char*     Form::GradeTooHighException::what( ) const throw()
{
	return  ("The grade is too High");
}

const char*     Form::GradeTooLowException::what( ) const throw()
{
	return  ("The grade is too Low");
}
