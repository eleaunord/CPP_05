#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

// concrete class derived from class AForm


class ShrubberyCreationForm
{
private:
	const std::string _target; // target of the form

public:
	// constructors & destructor
	ShrubberyCreationForm();
	// ref to name so no automatic copy + ensure original string unchanged
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();

	// getters


	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &ShrubberyCreationForm);
#endif