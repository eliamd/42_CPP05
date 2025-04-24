//
// Created by Eliam on 24/04/2025.
//

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form {
private:
	const std::string name;
	bool form_signed;
	const int grade_required_sign;
	const int grade_required_execution;

public:
	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CONSTRUCTORS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
	Form();

	Form(std::string name, bool form_signed, int grade_required_sign, int grade_required_execution);

	Form(const Form &other);

	Form &operator=(const Form &other);

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ DESTRUCTOR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

	~Form();

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ FUNCTIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

	void beSigned(const Bureaucrat &bureaucrat);

	void checkGrade(int grade);

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ GETTERS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

	std::string getName() const;

	bool getFormSigned() const;

	int getGradeRequiredSign() const;

	int getGradeRequiredExecution() const;

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ EXCEPTIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ OPERATOR OVERLOAD ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
std::ostream &operator<<(std::ostream &os, const Form &form);

#endif //FORM_HPP
