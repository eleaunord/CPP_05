#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(42)
{
	std::cout << "Bureaucrat's default constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw GradeTooLowException();
	}
	std::cout << "Bureaucrat's parameterized constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs) : _name(rhs._name), _grade(rhs._grade)
{
	std::cout << "Bureaucrat's copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy)
	{
		this->_grade = copy._grade;
	}
	std::cout << "Bureaucrat copy operator called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

// const to make sure getGrade won't modify the object + operator<< work that needs a const ref
int Bureaucrat::getGrade() const
{
	return _grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

void Bureaucrat::incrementGrade(int num)
{
	if (num <= 0)
	{
		throw GradeTooLowException();
	}
	if (_grade - num < 1)
	{
		throw GradeTooHighException();
	}
	_grade -= num;
}

void Bureaucrat::decrementGrade(int num)
{
	if (num <= 0)
	{
		throw GradeTooHighException();
	}
	if (_grade + num > 150)
	{
		throw GradeTooLowException();
	}
	_grade += num;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high mate!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low mate!";
}
void Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this); 
		std::cout << getName() << " signed " << form.getFormName() << std::endl;
	}
	catch (const std::exception &e)
	{

		std::cout << getName() << " couldn’t sign " << form.getFormName()
				  << " because " << e.what() << std::endl;
	}
}
