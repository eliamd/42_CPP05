//
// Created by Eliam on 25/04/2025.
//

#include "../includes/ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <fstream>

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CONSTRUCTOR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137), target("default") {
	std::cout << "\n┏━━ 🔨 ShrubberyCreationForm Default Constructor Called ━━" << std::endl;
	std::cout << "┃     name -> " << this->name << std::endl;
	std::cout << "┃     form_signed -> " << this->form_signed << std::endl;
	std::cout << "┃     getGradeRequiredSign -> " << this->getGradeRequiredSign() << std::endl;
	std::cout << "┃     getGradeRequiredExecution -> " << this->getGradeRequiredExecution() << std::endl;
	std::cout << "┃     target -> " << this->getTarget() << std::endl;
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(
		"ShrubberyCreationForm", false, 145, 137), target(target) {
	std::cout << "\n┏━━ 🔨 ShrubberyCreationForm Constructor with args Called ━━━" << std::endl;
	std::cout << "┃     name -> " << this->name << std::endl;
	std::cout << "┃     form_signed -> " << this->form_signed << std::endl;
	std::cout << "┃     getGradeRequiredSign -> " << this->getGradeRequiredSign() << std::endl;
	std::cout << "┃     getGradeRequiredExecution -> " << this->getGradeRequiredExecution() << std::endl;
	std::cout << "┃     target -> " << this->getTarget() << std::endl;
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target) {
	std::cout << "\n┏━━ 🔨 ShrubberyCreationForm Copy Constructor Called ━━━" << std::endl;
	std::cout << "┃     name -> " << this->name << std::endl;
	std::cout << "┃     form_signed -> " << this->form_signed << std::endl;
	std::cout << "┃     getGradeRequiredSign -> " << this->getGradeRequiredSign() << std::endl;
	std::cout << "┃     getGradeRequiredExecution -> " << this->getGradeRequiredExecution() << std::endl;
	std::cout << "┃     target -> " << this->getTarget() << std::endl;
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	this->form_signed = other.getFormSigned();

	std::cout << "\n┏━━🔨 ShrubberyCreationForm =Operator overload called ━━" << std::endl;
	std::cout << "┃     name -> " << this->name << std::endl;
	std::cout << "┃     form_signed -> " << this->form_signed << std::endl;
	std::cout << "┃     getGradeRequiredSign -> " << this->getGradeRequiredSign() << std::endl;
	std::cout << "┃     getGradeRequiredExecution -> " << this->getGradeRequiredExecution() << std::endl;
	std::cout << "┃     target -> " << this->getTarget() << std::endl;
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << std::endl;

	return (*this);
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ DESTRUCTOR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "\n━━🚫 ShrubberyCreationForm destructor called ━━" << std::endl;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ GETTERS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
std::string ShrubberyCreationForm::getTarget() {
	return (this->target);
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ SETTERS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ FUNCTIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

void ShrubberyCreationForm::beSigned(const Bureaucrat &bureaucrat) {
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

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!this->form_signed) {
		std::cout << "🔴 >> Form is not signed, cannot execute !" << std::endl;
		throw FormIsNotSignedException();
	}
	if (executor.getGrade() > this->getGradeRequiredExecution()) {
		std::cout << "🔴 >> cannot execute grade too low" << std::endl;
		throw GradeTooHighException();
	}
	std::cout << "🟢 >> " << executor.getName() << " executed " << this->getName() << std::endl;
	std::ofstream outfile((target + "_shrubbery").c_str());
	if (!outfile.is_open()) {
		throw std::runtime_error("Cannot create output file");
	}
	outfile << "       *      " << std::endl;
	outfile << "      ***     " << std::endl;
	outfile << "     *****    " << std::endl;
	outfile << "    *******   " << std::endl;
	outfile << "   *********  " << std::endl;
	outfile << "  *********** " << std::endl;
	outfile << " *************" << std::endl;
	outfile << "      |||     " << std::endl;
	outfile << "      |||     " << std::endl;
	outfile.close();
}
