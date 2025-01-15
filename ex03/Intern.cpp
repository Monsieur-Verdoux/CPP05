/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:56:38 by akovalev          #+#    #+#             */
/*   Updated: 2025/01/15 19:56:38 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &original)
{
	(void)original;
}

Intern &Intern::operator=(const Intern &original)
{
	(void)original;
	return (*this);
}

AForm *Intern::createShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

const char *Intern::FormNotFoundException::what() const noexcept
{
	return ("Form not found");
}


AForm *Intern::makeForm(std::string formName, std::string target)
{
	AForm *(Intern::*formCreators[3])(std::string target) = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm, 
		&Intern::createPresidentialPardonForm
		}; // alternatively typedef for the function pointer can be used, e.g. typedef AForm *(Intern::*formCreator)(std::string target);
	std::string formNames[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == formName)
		{
			return ((this->*formCreators[i])(target));
		}
	}
	throw FormNotFoundException();
	return (NULL);
}