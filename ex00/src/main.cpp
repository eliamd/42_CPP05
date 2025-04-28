//
// Created by Eliam on 23/04/2025.
//

#include "../includes/Bureaucrat.hpp"
#include <iostream>
#include <string>

int main()
{

	// Test Bureaucrat B1 (incrementGrade)
	Bureaucrat *B1 = NULL;
	try
	{
		B1 = new Bureaucrat("greg", 150);
	}
	catch (const std::exception &e)
	{
		std::cerr << "🔴 >>>> Erreur à la création de B1 : " << e.what() << std::endl;
	}

	if (B1)
	{
		std::cout << *B1 << std::endl;
		try
		{
			B1->incrementGrade();
			std::cout << "✅ Ok " << *B1 << std::endl;
		}
		catch (const Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << *B1 << std::endl;
		delete B1;
	}

	// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

	// Test Bureaucrat B2 (decrementGrade)
	Bureaucrat *B2 = NULL;
	try
	{
		B2 = new Bureaucrat("jean", 150);
	}
	catch (const std::exception &e)
	{
		std::cerr << "🔴 >>>> Erreur à la création de B2 : " << e.what() << std::endl;
	}

	if (B2)
	{
		std::cout << *B2 << std::endl;
		try
		{
			B2->decrementGrade();
			std::cout << "✅ Ok " << *B2 << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << *B2 << std::endl;
		delete B2;
	}

	return 0;
}
