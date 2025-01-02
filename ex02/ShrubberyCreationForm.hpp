#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"
#include <fstream>

// concrete class derived from class AForm


class ShrubberyCreationForm : public AForm
{
private:
	const std::string _target; // target of the form
	// set grades in constructor(?)

public:
	// constructors & destructor
	ShrubberyCreationForm();
	// ref to name so no automatic copy + ensure original string unchanged
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();

	// override execute function
	void execute(Bureaucrat const &executor) const;

};


#endif