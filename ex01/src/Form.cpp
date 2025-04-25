//
// Created by Eliam on 24/04/2025.
//

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include <stdexcept>
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CONSTRUCTORS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Form::Form() : name("Default"), form_signed(false), grade_required_sign(150), grade_required_execution(150) {
	std::cout << "🔨 >> Form created with default constructor" << std::endl;
}

Form::Form(std::string name, bool form_signed, int grade_required_sign, int grade_required_execution) : name(name),
	form_signed(form_signed),
	grade_required_sign(grade_required_sign), grade_required_execution(grade_required_execution) {
	checkGrade(this->grade_required_sign);
	checkGrade(this->grade_required_execution);
	std::cout << "🔨 >> Form created with args constructor" << std::endl;
}

Form::Form(const Form &other) : name(other.name), form_signed(other.form_signed),
                                grade_required_sign(other.grade_required_sign),
                                grade_required_execution(other.grade_required_execution) {
	checkGrade(this->grade_required_sign);
	checkGrade(this->grade_required_execution);
	std::cout << "🔨 >> Form created with copy constructor" << std::endl;
}

Form &Form::operator=(const Form &other) {
	this->form_signed = other.form_signed;
	std::cout << "🔨 >> Form created with assignement constructor" << std::endl;
	return (*this);
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ DESTRUCTOR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━


Form::~Form() {
	std::cout << "🚫 >>> Form destroyed" << std::endl;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ FUNCTIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━


void Form::checkGrade(const int grade) {
	if (grade > 150) {
		throw Form::GradeTooLowException();
	}
	if (grade < 1) {
		throw Form::GradeTooHighException();
	}
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
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

std::string Form::getName() const {
	return (this->name);
}

bool Form::getFormSigned() const {
	return (this->form_signed);
}

int Form::getGradeRequiredSign() const {
	return (this->grade_required_sign);
}

int Form::getGradeRequiredExecution() const {
	return (this->grade_required_execution);
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ EXCEPTIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

const char *Form::GradeTooLowException::what() const throw() {
	return ("🚨 >>>> Grade too low");
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("🚨 >>>> Grade too high");
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ OPERATOR OVERLOAD ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "> 📋 From => Name " << form.getName() << ", signed " << form.getFormSigned() << "." << std::endl;
	os << "Grade required for signing: " << form.getGradeRequiredSign() << std::endl;
	os << "Grade required for execution: " << form.getGradeRequiredExecution() << std::endl;
	return os;
}
