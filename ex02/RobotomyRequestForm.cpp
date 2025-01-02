#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _target("Default")
{
	std::cout << "RobotomyRequestForm's default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm's parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : AForm(rhs)
{
	std::cout << "RobotomyRequestForm's copy constructor called" << std::endl;
    *this = rhs;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    if (this != &copy)
	{
		//  _target cannot be reassigned because it is const
	}
	std::cout << "RobotomyRequestForm copy operator called" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

// generate random number with rand()
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::cout << "DRRRrrrrrrrrrrr (drilling noises)" << std::endl;
    if (rand() % 2)
        std::cout<<"The target has been robotomized!" << std::endl;
    else
        std::cout<< "The robotomy failed!" << std::endl;
}
