//
// Created by Eliam on 24/04/2025.
//

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include <stdexcept>
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CONSTRUCTORS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

AForm::AForm() : name("Default"), form_signed(false), grade_required_sign(150), grade_required_execution(150) {
	std::cout << "🔨 >> AForm created with default constructor" << std::endl;
}

AForm::AForm(std::string name, bool form_signed, int grade_required_sign, int grade_required_execution) : name(name),
	form_signed(form_signed),
	grade_required_sign(grade_required_sign), grade_required_execution(grade_required_execution) {
	checkGrade(this->grade_required_sign);
	checkGrade(this->grade_required_execution);
	std::cout << "🔨 >> AForm created with args constructor" << std::endl;
}

AForm::AForm(const AForm &other) : name(other.name), form_signed(other.form_signed),
                                grade_required_sign(other.grade_required_sign),
                                grade_required_execution(other.grade_required_execution) {
	checkGrade(this->grade_required_sign);
	checkGrade(this->grade_required_execution);
	std::cout << "🔨 >> AForm created with copy constructor" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
	this->form_signed = other.form_signed;
	std::cout << "🔨 >> AForm created with assignement constructor" << std::endl;
	return (*this);
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ DESTRUCTOR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━


AForm::~AForm() {
	std::cout << "🚫 >>> AForm destroyed" << std::endl;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ FUNCTIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━


void AForm::checkGrade(const int grade) {
	if (grade > 150) {
		throw AForm::GradeTooLowException();
	}
	if (grade < 1) {
		throw AForm::GradeTooHighException();
	}
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > 150) {
		throw GradeTooLowException();
	}
	if (bureaucrat.getGrade() < 1) {
		throw GradeTooHighException();
	}
	if (this->getGradeRequiredSign() >= bureaucrat.getGrade()) {
		std::cout << this->getName() << " sign " << this->getName() << "." << std::endl;
		this->form_signed = true;
	} else {
		std::cout << ">>> 🚫 " << bureaucrat.getName() << "  couldn’t sign " << bureaucrat.getName() <<
				" because he dosent have required grade to sign." << std::endl;
		throw GradeTooLowException();
	}
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ GETTERS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

std::string AForm::getName() const {
	return (this->name);
}

bool AForm::getFormSigned() const {
	return (this->form_signed);
}

int AForm::getGradeRequiredSign() const {
	return (this->grade_required_sign);
}

int AForm::getGradeRequiredExecution() const {
	return (this->grade_required_execution);
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ EXCEPTIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

const char *AForm::GradeTooLowException::what() const throw() {
	return ("🚨 >>>> Grade too low");
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("🚨 >>>> Grade too high");
}

const char *AForm::FormIsNotSignedException::what() const throw() {
	return ("🚨 >>>> Form is not signed");
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ OPERATOR OVERLOAD ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << "> 📋 From => Name " << form.getName() << ", signed " << form.getFormSigned() << "." << std::endl;
	os << "Grade required for signing: " << form.getGradeRequiredSign() << std::endl;
	os << "Grade required for execution: " << form.getGradeRequiredExecution() << std::endl;
	return os;
}
