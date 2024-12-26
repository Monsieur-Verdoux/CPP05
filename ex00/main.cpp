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
		std::cout << "----------------" << std::endl;
		std::cout << bur0;
		while (1)
			bur0.incrementGrade();
		std::cout << bur0;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat bur1("Finnan Finnanovich", 2);
		std::cout << "----------------" << std::endl;
		std::cout << bur1;
		bur1.incrementGrade();
		std::cout << bur1;
		bur1.incrementGrade();
		std::cout << bur1;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat bur2("Milad Miladovich", 149);
		std::cout << "----------------" << std::endl;
		std::cout << bur2;
		bur2.decrementGrade();
		std::cout << bur2;
		bur2.decrementGrade();
		std::cout << bur2;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat bur3("Ivan Ivanovich", 151);
		std::cout << "----------------" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try 
	{
		Bureaucrat bur4("Pyotr Petrovich", 0);
		std::cout << "----------------" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try 
	{
		Bureaucrat bur5;
		std::cout << bur5;
		std::cout << "----------------" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}