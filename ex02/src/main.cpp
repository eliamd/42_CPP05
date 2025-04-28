//
// Created by Eliam on 23/04/2025.
//

#include <iostream>
#include <string>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main()
{
	AForm *F = NULL;

	try
	{
		F = new ShrubberyCreationForm("caca");
	}
	catch (std::exception &e)
	{
		std::cerr << "🔴 >>>> Erreur à la création du formulaire : " << e.what() << std::endl;
	}

	if (F)
	{
		Bureaucrat jean("jean", 5);

		try
		{
			jean.signForm(*F);
		}
		catch (AForm::GradeTooHighException &e)
		{
			std::cerr << "🔴 >>>> Erreur test signForm; -> " << e.what() << std::endl;
		}

		try
		{
			jean.executeForm(*F);
		}
		catch (AForm::GradeTooHighException &e)
		{
			std::cerr << "🔴 >>>> Erreur test F->execute(jean); -> " << e.what() << std::endl;
		}
		catch (AForm::FormIsNotSignedException &e)
		{
			std::cerr << "🔴 >>>> Erreur test F->execute(jean); -> " << e.what() << std::endl;
		}

		delete F;
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
	// Test RobotomyRequestForm
	AForm *F2 = NULL;
	try
	{
		F2 = new RobotomyRequestForm("caca");
	}
	catch (std::exception &e)
	{
		std::cerr << "🔴 >>>> Erreur à la création du formulaire Robotomy : " << e.what() << std::endl;
	}

	if (F2)
	{
		Bureaucrat guy("guy", 5);

		try
		{
			guy.signForm(*F2);
		}
		catch (AForm::GradeTooHighException &e)
		{
			std::cerr << "🔴 >>>> Erreur test signForm; -> " << e.what() << std::endl;
		}

		try
		{
			guy.executeForm(*F2);
		}
		catch (AForm::GradeTooHighException &e)
		{
			std::cerr << "🔴 >>>> Erreur test F2->execute(guy); -> " << e.what() << std::endl;
		}
		catch (AForm::FormIsNotSignedException &e)
		{
			std::cerr << "🔴 >>>> Erreur test F2->execute(guy); -> " << e.what() << std::endl;
		}

		delete F2;
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

	// Test PresidentialPardonForm
	AForm *F3 = NULL;
	try
	{
		F3 = new PresidentialPardonForm("caca");
	}
	catch (std::exception &e)
	{
		std::cerr << "🔴 >>>> Erreur à la création du formulaire Presidential : " << e.what() << std::endl;
	}

	if (F3)
	{
		Bureaucrat adrien("adrien", 5);

		try
		{
			adrien.signForm(*F3);
		}
		catch (AForm::GradeTooHighException &e)
		{
			std::cerr << "🔴 >>>> Erreur test signForm; -> " << e.what() << std::endl;
		}

		try
		{
			adrien.executeForm(*F3);
		}
		catch (AForm::GradeTooHighException &e)
		{
			std::cerr << "🔴 >>>> Erreur test F3->execute(adrien); -> " << e.what() << std::endl;
		}
		catch (AForm::FormIsNotSignedException &e)
		{
			std::cerr << "🔴 >>>> Erreur test F3->execute(adrien); -> " << e.what() << std::endl;
		}

		delete F3;
	}

	return 0;
}
