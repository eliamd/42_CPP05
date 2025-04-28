//
// Created by Eliam on 28/04/2025.
//

#include "../includes/Intern.hpp"

#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"


Intern::Intern() {
    std::cout << "\n━━ 🔨 Intern Default Constructor Called ━━" << std::endl;
}

Intern::Intern(const Intern &other)
{
    std::cout << "━━ 🔨 Intern Copy Constructor Called ━━" << std::endl;
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    std::cout << "━━ 🔨 Intern Assignment Operator Called ━━" << std::endl;
    if (this == &other) {
        return *this;
    }
    return *this;
}

Intern::~Intern()
{
    std::cout << "━━ 🚫 Intern Destructor Called ━━" << std::endl;
}


static AForm	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

// Public Methods
AForm	*Intern::makeForm(const std::string form_to_create, const std::string target_for_form)
{
	AForm *(*all_forms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (form_to_create == forms[i])
		{
			std::cout << "Intern creates " << form_to_create << " now" << std::endl;
			return (all_forms[i](target_for_form));
		}
	}

	std::cout << "\033[33mIntern can not create a form called " << form_to_create << "\033[0m" << std::endl;
	return (NULL);
}
