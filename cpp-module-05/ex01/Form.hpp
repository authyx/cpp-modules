#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
private:
	std::string const   _name;
	bool                _signed;
	int const           _sign_grade;
	int const           _execute_grade;

public:
	Form();
	Form(const std::string& name, int signGrade, int executeGrade);
	Form(const Form& rhs);
	Form& operator = (const Form& rhs);
	~Form();

	std::string getName() const;
	bool        isSigned() const;
	int   gradeToSign() const;
	int   gradeToExecute() const;

	void	beSigned(const Bureaucrat& b);

	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream&  operator << (std::ostream& out, const Form& rhs);

#endif