#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default_name"), _grade(150)
{};

Bureaucrat::Bureaucrat(const Bureaucrat & org): _name(org._name), _grade(org._grade)
{
};


Bureaucrat& Bureaucrat::operator = (const Bureaucrat& rhs)
{
    _grade = rhs._grade;
    return (*this);
};


Bureaucrat::~Bureaucrat()
{};

std::string		Bureaucrat::getName() const
{
    return (_name);
}

int         	Bureaucrat::getGrade() const
{
    return (_grade);
}

void			Bureaucrat::incGrade()
{
    if ((_grade - 1) < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade -= 1;    
}

void			Bureaucrat::decGrade()
{
    if ((_grade + 1) > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade += 1;
    
}

void			Bureaucrat::setGrade(int newGrade)
{
    _grade = newGrade;
    if (_grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    if (_grade > 150)
        throw (Bureaucrat::GradeTooLowException());
}

std::ostream&  operator << (std::ostream& out, const Bureaucrat& rhs)
{
	out << rhs.getName() + ", bureaucrat grade " << rhs.getGrade() << std::endl;
    return (out);
}

const char*     Bureaucrat::GradeTooHighException::what( ) const throw()
{
	return  ("The grade is too High");
}

const char*     Bureaucrat::GradeTooLowException::what( ) const throw()
{
	return  ("The grade is too Low");
}
