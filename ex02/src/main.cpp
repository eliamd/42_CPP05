//
// Created by Eliam on 23/04/2025.
//

#include <iostream>
#include <string>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main() {
	Bureaucrat jean("jean", 5);
	AForm *F = new ShrubberyCreationForm("toto", false, 10, 5, "caca");
	try {
		jean.signForm(*F);
	} catch (AForm::GradeTooHighException &e) {
		std::cerr << "🔴 >>>> Erreur test signForm; -> " << e.what() << std::endl;
	}

	try {
		jean.executeForm(*F);
	} catch (AForm::GradeTooHighException &e) {
		std::cerr << "🔴 >>>> Erreur test F->execute(jean);; -> " << e.what() << std::endl;
	} catch (AForm::FormIsNotSignedException &e) {
		std::cerr << "🔴 >>>> Erreur test F->execute(jean);; -> " << e.what() << std::endl;
	}
	delete F;

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

	Bureaucrat guy("guy", 5);
	AForm *F2 = new RobotomyRequestForm("toto", false, 72, 45, "caca");
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

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

	Bureaucrat adrien("adrien", 5);
	AForm *F3 = new PresidentialPardonForm("toto", false, 72, 45, "caca");
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
