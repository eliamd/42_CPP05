//
// Created by Eliam on 25/04/2025.
//

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class ShrubberyCreationForm : public AForm {
private:
	const std::string target;

public:
	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CONSTRUCTOR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
	ShrubberyCreationForm();

	ShrubberyCreationForm(std::string target);

	ShrubberyCreationForm(const ShrubberyCreationForm &other);

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ DESTRUCTOR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

	~ShrubberyCreationForm();


	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ GETTERS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
	std::string getTarget();

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ SETTERS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ FUNCTIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
	virtual void beSigned(const Bureaucrat &bureaucrat);

	virtual void execute(Bureaucrat const &executor) const;

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ EXCEPTIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
};


#endif //SHRUBBERYCREATIONFORM_HPP
