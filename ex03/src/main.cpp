//
// Created by Eliam on 23/04/2025.
//

#include <iostream>
#include <string>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main() {
	Intern eliam;
	AForm *F1;

	F1 = eliam.makeForm("shrubberrt_form", "azu");


	Bureaucrat jean("jean", 5);
	try {
		jean.signForm(*F1);
	} catch (AForm::GradeTooHighException &e) {
		std::cerr << "🔴 >>>> Erreur test signForm; -> " << e.what() << std::endl;
	}

	try {
		jean.executeForm(*F1);
	} catch (AForm::GradeTooHighException &e) {
		std::cerr << "🔴 >>>> Erreur test F->execute(jean);; -> " << e.what() << std::endl;
	} catch (AForm::FormIsNotSignedException &e) {
		std::cerr << "🔴 >>>> Erreur test F->execute(jean);; -> " << e.what() << std::endl;
	}
	delete F1;

	std::cout << "\n ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n" <<
			std::endl;

	AForm *F2;

	F2 = eliam.makeForm("robo_form", "aza");

	Bureaucrat guy("guy", 5);
	try {
		guy.signForm(*F2);
	} catch (AForm::GradeTooHighException &e) {
		std::cerr << "🔴 >>>> Erreur test signForm; -> " << e.what() << std::endl;
	}

	try {
		guy.executeForm(*F2);
	} catch (AForm::GradeTooHighException &e) {
		std::cerr << "🔴 >>>> Erreur test F->execute(jean);; -> " << e.what() << std::endl;
	} catch (AForm::FormIsNotSignedException &e) {
		std::cerr << "🔴 >>>> Erreur test F->execute(jean);; -> " << e.what() << std::endl;
	}
	delete F2;

	std::cout << "\n ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n" <<
			std::endl;

	AForm *F3;

	F3 = eliam.makeForm("presidential_form", "Jean");

	Bureaucrat adrien("adrien", 5);
	try {
		adrien.signForm(*F3);
	} catch (AForm::GradeTooHighException &e) {
		std::cerr << "🔴 >>>> Erreur test signForm; -> " << e.what() << std::endl;
	}

	try {
		adrien.executeForm(*F3);
	} catch (AForm::GradeTooHighException &e) {
		std::cerr << "🔴 >>>> Erreur test F->execute(jean);; -> " << e.what() << std::endl;
	} catch (AForm::FormIsNotSignedException &e) {
		std::cerr << "🔴 >>>> Erreur test F->execute(jean);; -> " << e.what() << std::endl;
	}
	delete F3;


	return 0;
}
