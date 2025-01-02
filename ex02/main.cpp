#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>


int main()
{
	try
	{
		// bureaucrats
		Bureaucrat alice("Alice", 50);
		Bureaucrat bob("Bob", 100);
		Bureaucrat charlie("Charlie", 1); // Able to sign any form
		Bureaucrat fattah("Fattah", 150); // Can't sign any form
		std::cout << std::endl;

		// forms
		Form taxForm("TaxForm", 75, 50);	 // Needs grade 75 to sign, 50 to execute
		Form visaForm("VisaForm", 120, 110); // Needs grade 120 to sign, 110 to execute
		Form vipForm("VIPForm", 1, 1);		// ...
		Form investForm("InvestForm", 100, 100);
		std::cout << std::endl;

		// initial states
		std::cout << alice << std::endl;
		std::cout << bob << std::endl;
		std::cout << charlie << std::endl;
		std::cout << fattah << std::endl;
		std::cout << std::endl;
		std::cout << taxForm << std::endl;
		std::cout << visaForm << std::endl;
		std::cout << vipForm << std::endl;
		std::cout << investForm << std::endl;
		std::cout << std::endl;

		// Try signing the forms
		alice.signForm(taxForm); // succeed
		bob.signForm(taxForm);	 // fail (grade too low)
		bob.signForm(visaForm);	 // succeed
		charlie.signForm(vipForm); // fail (grade too high)
		fattah.signForm(investForm); // fail (grade too low)
		std::cout << std::endl;

		// final states of forms
		std::cout << taxForm << std::endl;
		std::cout << visaForm << std::endl;
		std::cout << vipForm << std::endl;
		std::cout << investForm << std::endl;
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "An error occurred: " << e.what() << std::endl;
	}

	return 0;
}
