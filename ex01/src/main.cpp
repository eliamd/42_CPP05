
//
// Created by Eliam on 23/04/2025.
//

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include <iostream>
#include <string>

int main() {
	Bureaucrat B1("greg", 1);

	std::cout << B1 << std::endl;
	try {
		B1.incrementGrade();
		std::cout << "✅ Ok" << B1 << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << "🔴 >>>> Erreur test B1.incrementGrade(); -> " << e.what() << std::endl;
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

	Bureaucrat B2("jean", 150);

	std::cout << B2 << std::endl;
	try {
		B2.decrementGrade();
		std::cout << "✅ Ok" << B2 << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << "🔴 >>>> Erreur test B2.decrementGrade(); -> " << e.what() << std::endl;
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━ Tests pour la classe Form ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
	std::cout << "\n----- TESTS DE LA CLASSE FORM -----\n" << std::endl;

	std::cout << "Test constructeur par défaut:" << std::endl;
	Form F1;
	std::cout << F1 << std::endl;

	std::cout << "Test constructeur avec arguments:" << std::endl;
	Form F2("Demande de vacances", false, 50, 25);
	std::cout << F2 << std::endl;

	std::cout << "Test de signature avec un grade suffisant:" << std::endl;
	std::cout << B1 << std::endl;
	try {
		B1.signForm(F2);
		std::cout << "✅ Formulaire signé avec succès" << std::endl;
		std::cout << F2 << std::endl;
	} catch (const Form::GradeTooLowException &e) {
		std::cerr << "🔴 >>>> Erreur test B1.signForm(F2); -> " << e.what() << std::endl;
	}

	std::cout << "Test de signature avec un grade insuffisant:" << std::endl;
	Form F3("Autorisation spéciale", false, 10, 5);
	try {
		Bureaucrat B3("Pierre", 20);
		B3.signForm(F3);
		std::cout << "✅ Formulaire signé avec succès" << std::endl;
	} catch (const Form::GradeTooLowException &e) {
		std::cerr << "🔴 >>>> Erreur test B3.signForm(F3); -> " << e.what() << std::endl;
	}

	std::cout << "\nTest avec grade invalide lors de la création:" << std::endl;
	try {
		Form F4("Formulaire impossible", false, 0, 10);
		std::cout << F4 << std::endl;
	} catch (const Form::GradeTooHighException &e) {
		std::cerr << "🔴 >>>> Erreur test Formulaire a 0 -> " << e.what() << std::endl;
	}

	try {
		Form F5("Formulaire impossible", false, 151, 10);
		std::cout << F5 << std::endl;
	} catch (const Form::GradeTooLowException &e) {
		std::cerr << "🔴 >>>> Erreur test Formulaire a 151 -> " << e.what() << std::endl;
	}

	std::cout << "Test du constructeur par copie:" << std::endl;
	Form F6(F2);
	std::cout << F6 << std::endl;

	return 0;
}
