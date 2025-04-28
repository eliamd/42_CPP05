//
// Created by Eliam on 23/04/2025.
//

#include <iostream>
#include <string>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
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


	return 0;
}
