#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"
#include <fstream>
#include <cstdlib> // for rand()

// concrete class derived from class AForm


class RobotomyRequestForm : public AForm
{
private:
	const std::string _target; // target of the form
	// set grades in constructor

public:
	// constructors & destructor
	RobotomyRequestForm();
	// ref to name so no automatic copy + ensure original string unchanged
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &rhs);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
	~RobotomyRequestForm();

	// override execute function => drilling noises
	void execute(Bureaucrat const &executor) const;

};


#endif