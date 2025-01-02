#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private :
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExec;

	public :
		// constructors & destructor
		AForm();
		// ref to name so no automatic copy + ensure original string unchanged
		AForm(const std::string &name, int gradeToSign, int gradeToExec);
		AForm(const AForm &rhs);
		AForm &operator=(const AForm &copy);
		virtual ~AForm();
		
		// getters
		const std::string &getAFormName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;

		// member functions
		bool beSigned(const Bureaucrat & bureaucrat); // change AForm status

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

std::ostream &operator<<(std::ostream &os, const AForm &AForm);
#endif