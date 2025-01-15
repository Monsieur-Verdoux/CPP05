/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 23:36:51 by akovalev          #+#    #+#             */
/*   Updated: 2024/12/26 23:36:51 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	try 
	{
		Bureaucrat bur0("Andrey Andreevich", 1);
		Intern fnan;

		try 
		{
			AForm *form0 = fnan.makeForm("Shrubbery Creation", "Hive");
			if (form0)
			{
				bur0.signForm(*form0);
				bur0.executeForm(*form0);
				delete form0;
			}
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "----------------" << std::endl;
		try 
		{
			AForm *form1 = fnan.makeForm("Robotomy Request", "Someone");
			if (form1)
			{
				bur0.signForm(*form1);
				bur0.executeForm(*form1);
				delete form1;
			}
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "----------------" << std::endl;
		try 
		{
			AForm *form2 = fnan.makeForm("Presidential Pardon", "Someone else");
			if (form2)
			{
				bur0.signForm(*form2);
				bur0.executeForm(*form2);
				delete form2;
			}
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "----------------" << std::endl;
		try 
		{
			AForm *form3 = fnan.makeForm("Unknown Form", "Someoner elser");
			if (form3)
			{
				bur0.signForm(*form3);
				bur0.executeForm(*form3);
				delete form3;
			}
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}