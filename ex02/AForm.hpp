#ifndef AFORM_HPP
#define AFORM_HPP

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
		const std::string &getFormName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;

		// member functions
		void beSigned(const Bureaucrat & bureaucrat); // change AForm status

		// pure virtual method
		virtual void execute(Bureaucrat const & executor) const = 0;

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
		class NotSignedException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		
};

std::ostream &operator<<(std::ostream &os, const AForm &AForm);
#endif