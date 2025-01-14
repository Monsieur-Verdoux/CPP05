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
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	try 
	{
		Bureaucrat bur0("Andrey Andreevich", 146);
		ShrubberyCreationForm form0("Home");
		std::cout << "----------------" << std::endl;
		bur0.executeForm(form0);
		bur0.signForm(form0);
		for (int i = 0; i < 9; i++)
		{
			bur0.incrementGrade();
		}
		bur0.signForm(form0);
		bur0.executeForm(form0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{

		std::cout << "----------------" << std::endl;
		RobotomyRequestForm form1("Hager Hagerovich");
		Bureaucrat bur0("Finnan Finnanovich", 1);	
		std::cout << "----------------" << std::endl;
		bur0.executeForm(form1);
		bur0.signForm(form1);
		bur0.executeForm(form1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try 
	{
		std::cout << "----------------" << std::endl;
		PresidentialPardonForm form2("Ryan Ryanovich");
		Bureaucrat bur0("Milad Miladovich", 1);	
		std::cout << "----------------" << std::endl;
		bur0.executeForm(form2);
		bur0.signForm(form2);
		bur0.executeForm(form2);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}