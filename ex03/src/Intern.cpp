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

AForm *Intern::makeForm(std::string form_name, std::string form_target) {
    switch ((form_name.find("robo") != std::string::npos)
                ? 1
                : (form_name.find("presi") != std::string::npos)
                      ? 2
                      : (form_name.find("shr") != std::string::npos)
                            ? 3
                            : 0) {
        case 1:
            std::cout << "🟢 >> Intern creates -> RobotomyRequestForm" << std::endl;
            return new RobotomyRequestForm(form_name, false, 72, 45, form_target);
        case 2:
            std::cout << "🟢 >> Intern creates -> PresidentialPardonForm" << std::endl;
            return new PresidentialPardonForm(form_name, false, 25, 5, form_target);
        case 3:
            std::cout << "🟢 >> Intern creates -> ShrubberyCreationForm" << std::endl;
            return new ShrubberyCreationForm(form_name, false, 145, 137, form_target);
        default:
            std::cout << "Error: Form '" << form_name << "' is not known" << std::endl;
            return NULL;
    }
}
