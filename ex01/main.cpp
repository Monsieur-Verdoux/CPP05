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

int main()
{
	try 
	{
		Bureaucrat bur0("Andrey Andreevich", 10);
		Form form0("Form 00", 10, 10);
		std::cout << "----------------" << std::endl;
		std::cout << bur0;
		std::cout << form0;
		bur0.signForm(form0);
		std::cout << form0;
		bur0.decrementGrade();
		std::cout << bur0;
		bur0.signForm(form0);
		std::cout << form0;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "----------------" << std::endl;
		std::cout << "Trying to create a form with a grade higher than 1" << std::endl;
		Form form1("Form 01", 0, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "----------------" << std::endl;
		std::cout << "Trying to create a form with a grade lower than 150" << std::endl;
		Form form2("Form 02", 151, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{

		std::cout << "----------------" << std::endl;
		Form form3;
		Form form4("Form 04", 1, 1);
		Bureaucrat bur0("Finnan Finnanovich", 1);	
		std::cout << std::endl;

		std::cout << form3;
		std::cout << form4;
		std::cout << std::endl;

		bur0.signForm(form4);
		form3 = form4;
		std::cout << form3;
		std::cout << std::endl;

		bur0.signForm(form3);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}