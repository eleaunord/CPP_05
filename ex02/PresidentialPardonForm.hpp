#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"
#include <fstream>

// concrete class derived from class AForm


class PresidentialPardonForm : public AForm
{
private:
	const std::string _target; // target of the form
	// set grades in constructor

public:
	// constructors & destructor
	PresidentialPardonForm();
	// ref to name so no automatic copy + ensure original string unchanged
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &rhfs);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
	~PresidentialPardonForm();

	// override execute function 
	void execute(Bureaucrat const &executor) const;

};


#endif