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

class AForm {
protected:
	const std::string name;
	bool form_signed;
	const int grade_required_sign;
	const int grade_required_execution;

public:
	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ CONSTRUCTORS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
	AForm();

	AForm(std::string name, bool form_signed, int grade_required_sign, int grade_required_execution);

	AForm(const AForm &other);

	AForm &operator=(const AForm &other);

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ DESTRUCTOR ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

	virtual ~AForm();

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ FUNCTIONS ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

	virtual void beSigned(const Bureaucrat &bureaucrat) = 0; // Abstract Class

	void checkGrade(int grade);

	virtual void execute(Bureaucrat const &executor) const = 0;

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

	class FormIsNotSignedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ OPERATOR OVERLOAD ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif //FORM_HPP
