#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class Form;

class Bureaucrat
{
private:
	std::string const _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat & org);
	Bureaucrat& operator = (const Bureaucrat& rhs);
	~Bureaucrat();

	std::string		getName() const;
	int				getGrade() const;
	void			incGrade();
	void			decGrade();

	void			setGrade(int newGrade);
	
	
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

	void signForm(Form& Form);
};

std::ostream&  operator << (std::ostream& out, const Bureaucrat& rhs);

#endif