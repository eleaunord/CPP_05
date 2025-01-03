#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern's constructor called" << std::endl;
}

Intern::Intern(const Intern &rhs)
{
	std::cout << "Intern's copy constructor called" << std::endl;
	*this = rhs;
}

Intern &Intern::operator=(const Intern &copy)
{
	if (this != &copy)
	{
		// no parameters
	}
	std::cout << "Intern copy operator called" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

// HELPER functions : create and return a pointer to a specific form type using the provided target string

static AForm *makeShrubbery(const std::string targetting)
{
	return (new ShrubberyCreationForm(targetting));
}

static AForm *makeRobotomy(const std::string targetting)
{
	return (new RobotomyRequestForm(targetting));
}

static AForm *makePresidential(const std::string targetting)
{
	return (new PresidentialPardonForm(targetting));
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return "Intern can't find the requested form";
}

AForm *Intern::makeForm(const std::string nameForm, const std::string targetForm)
{
	// array of function pointers => store pointers to the static form creation functions 
	// selection of the appropriate function dynamically based on the input string
	AForm *(*form_list[])(const std::string) = {&makeShrubbery,
											   &makeRobotomy,
											   &makePresidential};
	// matches form names to the corresponding function
	std::string form_strs[] = {"ShrubberyCreationForm",
							   "RobotomyRequestForm",
							   "PresidentialPardonForm"};

	for (int i = 0; i < 3; i++)
	{
		if (nameForm == form_strs[i])
		{
			std::cout << "Intern Creates " << nameForm << std::endl;
			return (form_list[i](targetForm));
		}
	}
	throw FormNotFoundException();
	return NULL;
}