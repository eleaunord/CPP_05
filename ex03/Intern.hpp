#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <exception>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{

	public:
		// CONSTRUCTORS
		// default constructor
		Intern();
		// copy constructor
		Intern(const Intern &rhs);
		// assignment operator (only grade can be reassigned)
		Intern &operator=(const Intern &copy);
		// destructor
		~Intern();

		// MEMBER FUNCTIONS
		AForm *makeForm(const std::string nameForm, const std::string targetForm);
		
		class FormNotFoundException:public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif
