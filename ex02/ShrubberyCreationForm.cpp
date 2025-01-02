#include "ShrubberyCreationForm.hpp"

// here we explicitly requests the parameterized constructor of AForm, overriding the implicit behavior where the default constructor of AForm would be called if no initializer is provided.
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("DefaultShrubberyCreationForm")
{
    std::cout << "ShrubberyCreationForm's default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm's parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs) : AForm(rhs)
{
	std::cout << "ShrubberyCreationForm's copy constructor called" << std::endl;
    *this = rhs;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    if (this != &copy)
	{
		//  _target cannot be reassigned because it is const
	}
	std::cout << "ShrubberyCreationForm copy operator called" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

// goal = Executes the form's action: creating a file named <target>_shrubbery containing an ASCII tree
// input = a Buraucrat object (the executor) to check if they have the necessary grade to execute the form
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    // 1/ ensure conditions for executing the form are met (= the form is signed, the executor has a sufficient grade to execute it)
    AForm::execute(executor);

    // 2/ create an output file stream to write a file (nb : .c_str converts the string to a c-style string)
    std::ofstream file((this->_target + "_shrubbery").c_str());
    file << "     ,*-~\"`^\"*u_                                _u*\"^`\"~-*,\n";
    file << "  p!^       /  jPw                            w9j \\        ^!p\n";
    file << "w^.._      /      \"\\_                      _/\"     \\        _.^w\n";
    file << "     *_   /          \\_      _    _      _/         \\     _* \n";
    file << "       q /           / \\q   ( `--` )   p/ \\          \\   p\n";
    file << "       jj5****._    /    ^\\_) o  o (_/^    \\    _.****6jj\n";
    file << "                *_ /      \"==) ;; (==\"      \\ _*\n";
    file << "                 `/.w***,   /(    )\\   ,***w.\\\"\n";
    file << "                  ^ ilmk ^c/ )    ( \\c^      ^\n";
    file << "                          'V')_)(_('V'\n";
    file << "                              `` ``\n";
    std::cout<< std::endl;
    file.close();

}