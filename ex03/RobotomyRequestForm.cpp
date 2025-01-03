#include "RobotomyRequestForm.hpp"

// here we explicitly requests the parameterized constructor of AForm, overriding the implicit behavior where the default constructor of AForm would be called if no initializer is provided.
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("DefaultRobotomyRequestForm")
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
	if (!this->getIsSigned())
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();

	std::cout << this->_target << " DRRRrrrr (drilling noises) " << std::endl;

	srand(time(NULL));
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized!" << std::endl;
	else
		std::cout << this->_target << "'s robotomy failed!" << std::endl;
}
