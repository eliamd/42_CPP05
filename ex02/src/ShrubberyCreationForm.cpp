//
// Created by Eliam on 25/04/2025.
//

#include "../includes/ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <fstream>

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CONSTRUCTOR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", false, 150, 150), target("default") {
	std::cout << "\n┏━━ 🔨 ShrubberyCreationForm Default Constructor Called ━━" << std::endl;
	std::cout << "┃     name -> " << this->name << std::endl;
	std::cout << "┃     form_signed -> " << this->form_signed << std::endl;
	std::cout << "┃     getGradeRequiredSign -> " << this->getGradeRequiredSign() << std::endl;
	std::cout << "┃     getGradeRequiredExecution -> " << this->getGradeRequiredExecution() << std::endl;
	std::cout << "┃     target -> " << this->getTarget() << std::endl;
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, bool form_signed, int grade_required_sign,
                                             int grade_required_execution, std::string target) : AForm(
		name, form_signed, grade_required_sign,
		grade_required_execution), target(target) {
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
	if (bureaucrat.getGrade() <= this->getGradeRequiredSign()) {
		this->form_signed = true;
	} else {
		throw GradeTooLowException();
	}
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!this->form_signed) {
		throw FormIsNotSignedException();
	}
	if (executor.getGrade() > this->getGradeRequiredExecution()) {
		throw GradeTooHighException();
	}
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
