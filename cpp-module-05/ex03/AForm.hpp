#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm
{
private:
	std::string const   _name;
	bool                _signed;
	int const           _sign_grade;
	int const           _execute_grade;

public:
	AForm();
	AForm(const std::string& name, int signGrade, int executeGrade);
	AForm(const AForm& rhs);
	AForm& operator = (const AForm& rhs);
	virtual ~AForm();

	std::string getName() const;
	bool        isSigned() const;
	int   gradeToSign() const;
	int   gradeToExecute() const;

	virtual void	beSigned(const Bureaucrat& b);

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

	class FormNotSignedException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	virtual void execute(Bureaucrat const& executor) const = 0;
};

std::ostream&  operator << (std::ostream& out, const AForm& rhs);

#endif