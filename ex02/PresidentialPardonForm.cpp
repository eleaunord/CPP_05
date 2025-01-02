#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _target("Default")
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
