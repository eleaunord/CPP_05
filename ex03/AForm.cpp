#include "AForm.hpp"

AForm::AForm() : _name("AForm Default"), _isSigned(false), _gradeToSign(42), _gradeToExec(42)
{
	std::cout << "AForm's default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	std::cout << "AForm's parameterized constructor called" << std::endl;
}

AForm::AForm(const AForm &rhs) : _name(rhs._name), _isSigned(rhs._isSigned), _gradeToSign(rhs._gradeToSign), _gradeToExec(rhs._gradeToExec)
{
	std::cout << "AForm's copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
	if (this != &copy)
	{
		this->_isSigned = copy._isSigned;
	}
	std::cout << "AForm copy operator called" << std::endl;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

const std::string &AForm::getFormName() const
{
	return _name;
}

// const to make sure getGrade won't modify the object + operator<< work that needs a const ref
int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExec() const
{
	return _gradeToExec;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
	os << AForm.getFormName() << ", is signed: " << (AForm.getIsSigned() ? "Yes" : "No") << ", grade required to sign it: " << AForm.getGradeToSign() << ", grade required to execute it: " << AForm.getGradeToExec();
	return os;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
	{
		_isSigned = true;
	}
	else
	{
		throw GradeTooLowException();
	}
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!_isSigned)
		throw NotSignedException();
	else if (executor.getGrade() > _gradeToExec)
		throw GradeTooLowException();

}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high mate!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low mate!";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "Form not signed mate!";
}
