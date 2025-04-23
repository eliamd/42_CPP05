//
// Created by Eliam on 23/04/2025.
//

#include "../includes/Bureaucrat.hpp"
#include <iostream>
#include <string>

int main() {
	Bureaucrat B1("greg", 1);

	std::cout << B1 << std::endl;
	try {
		B1.incrementGrade();
		std::cout << "✅ Ok" << B1 << std::endl;
	} catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

	Bureaucrat B2("jean", 149);

	std::cout << B2 << std::endl;
	try {
		B2.decrementGrade();
		std::cout << "✅ Ok" << B2 << std::endl;
	} catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
