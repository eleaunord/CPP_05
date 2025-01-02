#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    // Test 1: Bureaucrat and Form Creation
    try
    {
        std::cout << "\n--- Test 1: Bureaucrat and Form Creation ---\n";

        Bureaucrat alice("Alice", 50);
        Bureaucrat chat("Chat", 140);
        Bureaucrat chapelier("Chapelier", 1);

        ShrubberyCreationForm shrubbery("Jardin imaginaire"); // Required grades: sign 145, exec 137
        RobotomyRequestForm robotomy("Robot magique");        // Required grades: sign 72, exec 45
        PresidentialPardonForm pardon("Reine de coeur");      // Required grades: sign 25, exec 5
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error in Test 1: " << e.what() << std::endl;
    }

    // Test 2: Signing Forms
    try
    {
        std::cout << "\n--- Test 2: Signing Forms ---\n";

        Bureaucrat alice("Alice", 50);
        Bureaucrat chat("Chat", 140);
        Bureaucrat chapelier("Chapelier", 1);
        Bureaucrat reine("Reine", 42);

        ShrubberyCreationForm shrubbery("Jardin imaginaire");
        RobotomyRequestForm robotomy("Robot magique");
        PresidentialPardonForm pardon("Reine de coeur");

        std::cout << std::endl;

        chat.signForm(shrubbery); // chat can sign 
        alice.signForm(robotomy); // alice can sign 
        chapelier.signForm(pardon); // chapelier can sign everything
        reine.signForm(pardon); // reine cannot sign
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error in Test 2: " << e.what() << std::endl;
    }

    // Test 3: Executing Forms
    try
    {
        std::cout << "\n--- Test 3: Executing Forms ---\n";

        Bureaucrat alice("Alice", 50);
        Bureaucrat chat("Chat", 140);
        Bureaucrat chapelier("Chapelier", 1);

        ShrubberyCreationForm shrubbery("Jardin imaginaire");
        RobotomyRequestForm robotomy("Robot magique");
        PresidentialPardonForm pardon("Reine de coeur");
        
        // WORKS
        std::cout << std::endl;
        std::cout << "\n--- Testing PresidentialPardonForm ---\n";
        pardon.beSigned(chapelier);
        pardon.execute(chapelier);

        std::cout << std::endl;
        std::cout << "\n--- Testing ShrubberyCreationForm (check file creation) ---\n";
        shrubbery.beSigned(chapelier);
        shrubbery.execute(chapelier);

        std::cout << std::endl;
        std::cout << "\n--- Testing RobotomyRequestForm ---\n";
        robotomy.beSigned(chapelier);
        robotomy.execute(chapelier);

        // DOES NOT WORK
        std::cout << std::endl;
        shrubbery.beSigned(chat);
        shrubbery.execute(chat); // form requires an execution grade of 137, but chat's grade (140) is too low.

        std::cout << std::endl;

        robotomy.beSigned(alice);
        robotomy.execute(alice); // executing the form requires a grade of 45, and alice's grade (50) is too low.

    }
    catch (const std::exception &e)
    {
        std::cerr << "Error in Test 3: " << e.what() << std::endl;
    }

    // Test 4: Exceptions During Execution
    try
    {
        std::cout << "\n--- Test 4: Exceptions During Execution ---\n";

        Bureaucrat alice("Alice", 50);
        Bureaucrat chat("Chat", 140);
        Bureaucrat chapelier("Chapelier", 1);

        ShrubberyCreationForm shrubbery("Jardin imaginaire");
        RobotomyRequestForm robotomy("Robot magique");
        PresidentialPardonForm pardon("Reine de coeur");

        std::cout << std::endl;

        // attempting to execute forms without signing them first
        try
        {
            shrubbery.execute(alice);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        std::cout << std::endl;

        try
        {
            robotomy.execute(chat);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        std::cout << std::endl;

        try
        {
            PresidentialPardonForm unsignedForm("Unsigned_Target");
            unsignedForm.execute(chapelier);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error in Test 4: " << e.what() << std::endl;
    }

    // Test 5: Using Default Constructors
    try
    {
        std::cout << "\n--- Test 5: Using Default Constructors ---\n";

        Bureaucrat defaultBureaucrat;
        std::cout << "Default Bureaucrat: Name = " << defaultBureaucrat.getName()
                  << ", Grade = " << defaultBureaucrat.getGrade() << std::endl;

        std::cout << std::endl;

        ShrubberyCreationForm defaultShrubbery;
        std::cout << "Default ShrubberyCreationForm: Name = " << defaultShrubbery.getFormName()
                  << ", Required Grades: Sign = " << defaultShrubbery.getGradeToSign()
                  << ", Exec = " << defaultShrubbery.getGradeToExec() << std::endl;

        std::cout << std::endl;

        RobotomyRequestForm defaultRobotomy;
        std::cout << "Default RobotomyRequestForm: Name = " << defaultRobotomy.getFormName()
                  << ", Required Grades: Sign = " << defaultRobotomy.getGradeToSign()
                  << ", Exec = " << defaultRobotomy.getGradeToExec() << std::endl;

        std::cout << std::endl;

        PresidentialPardonForm defaultPardon;
        std::cout << "Default PresidentialPardonForm: Name = " << defaultPardon.getFormName()
                  << ", Required Grades: Sign = " << defaultPardon.getGradeToSign()
                  << ", Exec = " << defaultPardon.getGradeToExec() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error in Test 5: " << e.what() << std::endl;
    }

    return 0;
}
