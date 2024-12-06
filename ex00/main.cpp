#include "Bureaucrat.hpp"
#include <iostream>


int main()
{
	try
	{
		// default constructor
		Bureaucrat defaultBureaucrat;
		std::cout << "Default Bureaucrat: " << defaultBureaucrat << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		// NO
		// copy constructor
		Bureaucrat alice("Alice", 5);
		std::cout << "Original Bureaucrat: " << alice << std::endl;

		Bureaucrat aliceCopy(alice); 
		std::cout << "Copied Bureaucrat: " << aliceCopy << std::endl;

		alice.incrementGrade(3);
		std::cout << "After upgrading the original: " << alice << std::endl;
		std::cout << "Copied Bureaucrat remains the same: " << aliceCopy << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat bob("Bob", 148);
		std::cout << bob << std::endl;

		// valid
		bob.decrementGrade(2);
		std::cout << "After downgrading: " << bob << std::endl;

		//invalid (too low)
		bob.decrementGrade(3);
		std::cout << "This line won't be printed out because exception will be thrown. " << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		// NO
		Bureaucrat bobby("Bobby", 4);

		// valid
		bobby.incrementGrade(2);
		std::cout << "After incrementing: " << bobby << std::endl;

		// invalid (too high)
		bobby.incrementGrade(2);
		std::cout << "This line won't be printed out because exception will be thrown. " << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	try
	{
		// invalid (too high)
		Bureaucrat invalidHigh("Carol", 0);
		std::cout << "This line won't be printed out because exception will be thrown. " << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		// invalid (too low)
		Bureaucrat invalidLow("Dave", 151);
		std::cout << "This line won't be printed out because exception will be thrown. " << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
