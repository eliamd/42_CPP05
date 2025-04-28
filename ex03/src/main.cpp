//
// Created by Eliam on 23/04/2025.
//

#include <iostream>
#include <string>
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main()
{
	Intern eliam;
	AForm *F1 = NULL;

	try
	{
		F1 = eliam.makeForm("ShrubberyCreationForm", "azu");
	}
	catch (const std::exception &e)
	{
		std::cerr << "🔴 >>>> Erreur à la création du formulaire F1 : " << e.what() << std::endl;
	}

	if (F1 != NULL)
	{
		Bureaucrat jean("jean", 5);
		try
		{
			jean.signForm(*F1);
		}
		catch (AForm::GradeTooHighException &e)
		{
			std::cerr << "🔴 >>>> Erreur test signForm; -> " << e.what() << std::endl;
		}

		try
		{
			jean.executeForm(*F1);
		}
		catch (AForm::GradeTooHighException &e)
		{
			std::cerr << "🔴 >>>> Erreur test F1->execute(jean); -> " << e.what() << std::endl;
		}
		catch (AForm::FormIsNotSignedException &e)
		{
			std::cerr << "🔴 >>>> Erreur test F1->execute(jean); -> " << e.what() << std::endl;
		}

		delete F1;
	}

	std::cout << "\n ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n"
			  << std::endl;

	AForm *F2 = NULL;
	try
	{
		F2 = eliam.makeForm("PresidentialPardonForm", "aza");
	}
	catch (const std::exception &e)
	{
		std::cerr << "🔴 >>>> Erreur à la création du formulaire F2 : " << e.what() << std::endl;
	}

	if (F2 != NULL)
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

	std::cout << "\n ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ \n"
			  << std::endl;

	AForm *F3 = NULL;
	try
	{
		F3 = eliam.makeForm("RobotomyRequestForm", "Jean");
	}
	catch (const std::exception &e)
	{
		std::cerr << "🔴 >>>> Erreur à la création du formulaire F3 : " << e.what() << std::endl;
	}

	if (F3 != NULL)
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
