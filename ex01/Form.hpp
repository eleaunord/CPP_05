#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private :
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExec;

	public :
		// constructors & destructor
		Form();
		// ref to name so no automatic copy + ensure original string unchanged
		Form(const std::string &name, int gradeToSign, int gradeToExec);
		Form(const Form &rhs);
		Form &operator=(const Form &copy);
		~Form();
		
		// getters
		const std::string &getFormName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;

		// member functions
		bool beSigned(const Bureaucrat & bureaucrat); // change form status

		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Form &form);
#endif