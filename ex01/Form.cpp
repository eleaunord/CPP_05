#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(42), _gradeToExec(42)
{
	std::cout << "Form's default constructor called" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	std::cout << "Form's parameterized constructor called" << std::endl;
}

Form::Form(const Form &rhs) : _name(rhs._name), _isSigned(rhs._isSigned), _gradeToSign(rhs._gradeToSign), _gradeToExec(rhs._gradeToExec)
{
	std::cout << "Form's copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &copy)
{
	if (this != &copy)
	{
		this->_isSigned = copy._isSigned;
	}
	std::cout << "Form copy operator called" << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

const std::string &Form::getName() const
{
	return _name;
}

// const to make sure getGrade won't modify the object + operator<< work that needs a const ref
int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExec() const
{
	return _gradeToExec;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << form.getName() << ", is signed: " << (form.getIsSigned() ? "Yes" : "No") << ", grade required to sign it: " << form.getGradeToSign() << ", grade required to execute it: " << form.getGradeToExec();
	return os;
}

bool Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
	{
		_isSigned = true;
		return true;
	}
	else
	{
		throw GradeTooLowException();
	}
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high mate!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low mate!";
}