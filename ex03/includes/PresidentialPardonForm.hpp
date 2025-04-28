//
// Created by Eliam on 25/04/2025.
//

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class PresidentialPardonForm : public AForm {
private:
	const std::string target;

public:
	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CONSTRUCTOR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
	PresidentialPardonForm();

	PresidentialPardonForm(std::string name, bool form_signed, int grade_required_sign, int grade_required_execution,
	                       std::string target);

	PresidentialPardonForm(const PresidentialPardonForm &other);

	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ DESTRUCTOR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

	~PresidentialPardonForm();


	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ GETTERS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
	std::string getTarget();

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ SETTERS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ FUNCTIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
	virtual void beSigned(const Bureaucrat &bureaucrat);

	virtual void execute(Bureaucrat const &executor) const;

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ EXCEPTIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
};


#endif //PRESIDENTIALPARDONFORM_HPP
