//
// Created by Eliam on 23/04/2025.
//

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include <stdexcept>

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CONSTRUCTORS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {
	std::cout << "🔨 >> Bureaucrat created with default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
	if (this->grade > 150) {
		throw GradeTooLowException();
	} else if (this->grade < 1) {
		throw GradeTooHighException();
	}
	std::cout << "🔨 >> Bureaucrat created with args constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {
	if (this->grade > 150) {
		throw GradeTooLowException();
	} else if (this->grade < 1) {
		throw GradeTooHighException();
	}
	std::cout << "🔨 >> Bureaucrat created with copy constructor" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	this->grade = other.grade;
	std::cout << "🔨 >> Bureaucrat created with assignement constructor" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "🚫 >> Bureaucrat destroyed" << std::endl;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ GETTERS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━


std::string Bureaucrat::getName() const {
	return (this->name);
}

int Bureaucrat::getGrade() const {
	return (this->grade);
}


// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ SETTERS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

void Bureaucrat::setGrade(int grade) {
	this->grade = grade;
}

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ FUNCTIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

void Bureaucrat::incrementGrade() {
	if (this->grade > 150) {
		throw GradeTooLowException();
	} else if (this->grade < 2) {
		throw GradeTooHighException();
	}
	this->grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->grade > 149) {
		throw GradeTooLowException();
	} else if (this->grade < 1) {
		throw GradeTooHighException();
	}
	this->grade++;
}

void Bureaucrat::signForm(AForm &form) {
	form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const &form) {
	form.execute(*this);
}


// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ EXCEPTIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return os;
};
