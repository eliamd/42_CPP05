//
// Created by Eliam on 25/04/2025.
//

#include "../includes/PresidentialPardonForm.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <cstdlib>

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CONSTRUCTOR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", false, 150, 150), target("default") {
	std::cout << "\n┏━━ 🔨 PresidentialPardonForm Default Constructor Called ━━" << std::endl;
	std::cout << "┃     name -> " << this->name << std::endl;
	std::cout << "┃     form_signed -> " << this->form_signed << std::endl;
	std::cout << "┃     getGradeRequiredSign -> " << this->getGradeRequiredSign() << std::endl;
	std::cout << "┃     getGradeRequiredExecution -> " << this->getGradeRequiredExecution() << std::endl;
	std::cout << "┃     target -> " << this->getTarget() << std::endl;
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, bool form_signed, int grade_required_sign,
                                               int grade_required_execution, std::string target) : AForm(
	name, form_signed, grade_required_sign,
	grade_required_execution), target(target) {
	std::cout << "\n┏━━ 🔨 PresidentialPardonForm Constructor with args Called ━━━" << std::endl;
	std::cout << "┃     name -> " << this->name << std::endl;
	std::cout << "┃     form_signed -> " << this->form_signed << std::endl;
	std::cout << "┃     getGradeRequiredSign -> " << this->getGradeRequiredSign() << std::endl;
	std::cout << "┃     getGradeRequiredExecution -> " << this->getGradeRequiredExecution() << std::endl;
	std::cout << "┃     target -> " << this->getTarget() << std::endl;
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other),
	target(other.target) {
	std::cout << "\n┏━━ 🔨 PresidentialPardonForm Copy Constructor Called ━━━" << std::endl;
	std::cout << "┃     name -> " << this->name << std::endl;
	std::cout << "┃     form_signed -> " << this->form_signed << std::endl;
	std::cout << "┃     getGradeRequiredSign -> " << this->getGradeRequiredSign() << std::endl;
	std::cout << "┃     getGradeRequiredExecution -> " << this->getGradeRequiredExecution() << std::endl;
	std::cout << "┃     target -> " << this->getTarget() << std::endl;
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	this->form_signed = other.getFormSigned();

	std::cout << "\n┏━━🔨 PresidentialPardonForm =Operator overload called ━━" << std::endl;
	std::cout << "┃     name -> " << this->name << std::endl;
	std::cout << "┃     form_signed -> " << this->form_signed << std::endl;
	std::cout << "┃     getGradeRequiredSign -> " << this->getGradeRequiredSign() << std::endl;
	std::cout << "┃     getGradeRequiredExecution -> " << this->getGradeRequiredExecution() << std::endl;
	std::cout << "┃     target -> " << this->getTarget() << std::endl;
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << std::endl;

	return (*this);
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ DESTRUCTOR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "\n━━🚫 PresidentialPardonForm destructor called ━━" << std::endl;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ GETTERS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
std::string PresidentialPardonForm::getTarget() {
	return (this->target);
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ SETTERS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ FUNCTIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

void PresidentialPardonForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > 150) {
		throw GradeTooLowException();
	}
	if (bureaucrat.getGrade() < 1) {
		throw GradeTooHighException();
	}
	if (this->getGradeRequiredSign() >= bureaucrat.getGrade()) {
		std::cout << "🟢 >> " << bureaucrat.getName() << " sign " << this->getName() << "." << std::endl;
		this->form_signed = true;
	} else {
		std::cout << ">>> 🚫 " << bureaucrat.getName() << "  couldn’t sign " << bureaucrat.getName() <<
				" because he dosent have required grade to sign." << std::endl;
		throw GradeTooLowException();
	}
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!this->form_signed) {
		std::cout << "🔴 >> Form is not signed, cannot execute !" << std::endl;
		throw FormIsNotSignedException();
	}
	if (executor.getGrade() > this->getGradeRequiredExecution()) {
		std::cout << "🔴 >> cannot execute grade too low" << std::endl;
		throw GradeTooHighException();
	}

	std::cout << "🟢 >> " << executor.getName() << " executed " << this->getName() << std::endl;
	std::cout << "🟢 >> " << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
