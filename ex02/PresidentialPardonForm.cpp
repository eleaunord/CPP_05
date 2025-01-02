#include "PresidentialPardonForm.hpp"

// here we explicitly requests the parameterized constructor of AForm, overriding the implicit behavior where the default constructor of AForm would be called if no initializer is provided.
PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target("DefaultPresidentialPardonForm")
{
	std::cout << "PresidentialPardonForm's default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm's parameterized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) : AForm(rhs)
{
	std::cout << "PresidentialPardonForm's copy constructor called" << std::endl;
    *this = rhs;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this != &copy)
	{
		//  _target cannot be reassigned because it is const
	}
	std::cout << "PresidentialPardonForm copy operator called" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}


void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
