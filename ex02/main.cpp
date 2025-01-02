#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try
    {
        // creation of Bureaucrats using parameterized constructors
        Bureaucrat alice("Alice", 50);
        Bureaucrat chat("Chat", 140);
        Bureaucrat chapelier("chapelier", 1);

		std::cout << std::endl;

        // creation of forms : calling AForm's parameterized constructor first since the other classes are derived from it 
        ShrubberyCreationForm shrubbery("Jardin imaginaire"); // Required grades: sign 145, exec 137
        RobotomyRequestForm robotomy("Robot magique"); // Required grades: sign 72, exec 45
        PresidentialPardonForm pardon("Reine de coeur"); // Required grades: sign 25, exec 5

		std::cout << std::endl;

        std::cout << "\n--- Signing Forms ---\n";
        chat.signForm(shrubbery); // chat can sign ShrubberyCreationForm
        alice.signForm(robotomy); // Alice can sign RobotomyRequestForm
        chapelier.signForm(pardon); // chapelier can sign PresidentialPardonForm

		std::cout << std::endl;

        std::cout << "\n--- Executing Forms ---\n";
        chat.executeForm(shrubbery); // chat executes ShrubberyCreationForm
        alice.executeForm(robotomy); // Alice executes RobotomyRequestForm
        chapelier.executeForm(pardon); // chapelier executes PresidentialPardonForm

		std::cout << std::endl;

        // insufficient grade to execute
        std::cout << "\n--- Testing Execution Exceptions ---\n";
        chat.executeForm(robotomy); // chat cannot execute RobotomyRequestForm
        alice.executeForm(pardon); // Alice cannot execute PresidentialPardonForm

		std::cout << std::endl;

        std::cout << "\n--- Testing Unsigned Form Execution ---\n";
        PresidentialPardonForm unsignedForm("Unsigned_Target");
        chapelier.executeForm(unsignedForm); // chapelier cannot execute an unsigned form
		
		std::cout << std::endl;

    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
