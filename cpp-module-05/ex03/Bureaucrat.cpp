#include "AForm.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("MyBureaucrat"), _grade(150)
{};

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

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
	if (newGrade < 1)
		throw (Bureaucrat::GradeTooHighException());
    if (newGrade > 150)
		throw (Bureaucrat::GradeTooLowException());
    _grade = newGrade;
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

void Bureaucrat::signForm(AForm& Form)
{
	try
	{
		Form.beSigned(*this);
		std::cout << this->getName() + " signed " + Form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " + Form.getName() + " because " << e.what() << '\n';
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() + " executed " + form.getName() << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << this->getName() + " couldn't execute " + form.getName() + " because " << e.what() << std::endl;
	}
}
