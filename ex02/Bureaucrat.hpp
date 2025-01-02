#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#include "Form.hpp"

class Form;

class Bureaucrat
{
	private :
		const std::string _name;
		int _grade; // between 1 and 150

	public:
		// CONSTRUCTORS
		// default constructor
		Bureaucrat();
		// parameterized constructor
		Bureaucrat(const std::string &name, int grade);
		// copy constructor
		Bureaucrat(const Bureaucrat &rhs);
		// assignment operator (only grade can be reassigned)
		Bureaucrat &operator=(const Bureaucrat &copy);
		// destructor
		~Bureaucrat();

		// MEMBER FUNCTIONS
		// getters
		std::string getName() const;
		int getGrade() const;
		// functions
		void incrementGrade(int num); // => grade too high exception
		void decrementGrade(int num); // => grade too low exception

		// new
		void signForm(Form &form) const;

		// EXCEPTIONS
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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
