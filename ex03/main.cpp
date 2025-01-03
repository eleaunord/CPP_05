#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cassert> 

int main()
{
    try
    {
        std::cout << "\n Intern Class Testing \n";

        // Create an Intern
        Intern someRandomIntern;

        // Test cases for valid form creation
        try
        {
            std::cout << "\n Testing Valid Form Creation \n";

            // Create a ShrubberyCreationForm
            AForm *shrubForm = someRandomIntern.makeForm("ShrubberyCreationForm", "Home");
            std::cout << *shrubForm << std::endl;
            delete shrubForm;

            // Create a RobotomyRequestForm
            AForm *robotForm = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
            std::cout << *robotForm << std::endl;
            delete robotForm;

            // Create a PresidentialPardonForm
            AForm *pardonForm = someRandomIntern.makeForm("PresidentialPardonForm", "Alice");
            std::cout << *pardonForm << std::endl;
            delete pardonForm;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error during valid form creation: " << e.what() << std::endl;
        }

        // Test case for invalid form creation
        try
        {
            std::cout << "\n Testing Invalid Form Creation \n";
            AForm *invalidForm = someRandomIntern.makeForm("InvalidFormType", "Target");
            delete invalidForm; // This line will never be reached
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        // Test signing a form
        try
        {
            std::cout << "\n Testing Form Signing \n";

            Bureaucrat bob("Bob", 50); // Bob has a grade sufficient for signing RobotomyRequestForm
            AForm *robotForm = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
            std::cout << *robotForm << std::endl;

            robotForm->beSigned(bob); // Bob signs the form
            std::cout << *robotForm << std::endl;

            delete robotForm;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error during form signing: " << e.what() << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unhandled Error: " << e.what() << std::endl;
    }

    return 0;
}
