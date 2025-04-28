//
// Created by Eliam on 25/04/2025.
//

#include "../includes/RobotomyRequestForm.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <cstdlib>

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CONSTRUCTOR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", false, 72, 45), target("default") {
	std::cout << "\n┏━━ 🔨 RobotomyRequestForm Default Constructor Called ━━" << std::endl;
	std::cout << "┃     name -> " << this->name << std::endl;
	std::cout << "┃     form_signed -> " << this->form_signed << std::endl;
	std::cout << "┃     getGradeRequiredSign -> " << this->getGradeRequiredSign() << std::endl;
	std::cout << "┃     getGradeRequiredExecution -> " << this->getGradeRequiredExecution() << std::endl;
	std::cout << "┃     target -> " << this->getTarget() << std::endl;
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(
		"RobotomyRequestForm", false, 72,
		45), target(target) {
	std::cout << "\n┏━━ 🔨 RobotomyRequestForm Constructor with args Called ━━━" << std::endl;
	std::cout << "┃     name -> " << this->name << std::endl;
	std::cout << "┃     form_signed -> " << this->form_signed << std::endl;
	std::cout << "┃     getGradeRequiredSign -> " << this->getGradeRequiredSign() << std::endl;
	std::cout << "┃     getGradeRequiredExecution -> " << this->getGradeRequiredExecution() << std::endl;
	std::cout << "┃     target -> " << this->getTarget() << std::endl;
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target) {
	std::cout << "\n┏━━ 🔨 RobotomyRequestForm Copy Constructor Called ━━━" << std::endl;
	std::cout << "┃     name -> " << this->name << std::endl;
	std::cout << "┃     form_signed -> " << this->form_signed << std::endl;
	std::cout << "┃     getGradeRequiredSign -> " << this->getGradeRequiredSign() << std::endl;
	std::cout << "┃     getGradeRequiredExecution -> " << this->getGradeRequiredExecution() << std::endl;
	std::cout << "┃     target -> " << this->getTarget() << std::endl;
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	this->form_signed = other.getFormSigned();

	std::cout << "\n┏━━🔨 RobotomyRequestForm =Operator overload called ━━" << std::endl;
	std::cout << "┃     name -> " << this->name << std::endl;
	std::cout << "┃     form_signed -> " << this->form_signed << std::endl;
	std::cout << "┃     getGradeRequiredSign -> " << this->getGradeRequiredSign() << std::endl;
	std::cout << "┃     getGradeRequiredExecution -> " << this->getGradeRequiredExecution() << std::endl;
	std::cout << "┃     target -> " << this->getTarget() << std::endl;
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << std::endl;

	return (*this);
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ DESTRUCTOR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "\n━━🚫 RobotomyRequestForm destructor called ━━" << std::endl;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ GETTERS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
std::string RobotomyRequestForm::getTarget() {
	return (this->target);
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ SETTERS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ FUNCTIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

void RobotomyRequestForm::beSigned(const Bureaucrat &bureaucrat) {
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

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	srand(time(0));
	int random_number = rand() % 2;

	if (!this->form_signed) {
		std::cout << "🔴 >> Form is not signed, cannot execute !" << std::endl;
		throw FormIsNotSignedException();
	}
	if (executor.getGrade() > this->getGradeRequiredExecution()) {
		std::cout << "🔴 >> cannot execute grade too low" << std::endl;
		throw GradeTooHighException();
	}

	std::cout << "🟢 >> " << executor.getName() << " executed " << this->getName() << std::endl;
	std::cout << "* DRILL NOISES*" << std::endl;

	if (random_number == 1) {
		std::cout << "🤖 >> " << this->target << " has been robotomized !" << std::endl;
	} else {
		std::cout << "🤖 >> " << this->target << " failed to be robotomized !" << std::endl;
	}
}
