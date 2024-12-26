/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 23:36:18 by akovalev          #+#    #+#             */
/*   Updated: 2024/12/26 23:36:18 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Defaultcrat"), _grade(150)
{
	std::cout << "A default bureaucrat is born" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cout << "A bureaucrat " << _name << " is born " << "with grade " << _grade << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "A bureaucrat " << _name << " perishes" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &original) : _name(original._name), _grade(original._grade)
{
	std::cout << "A bureaucrat " << _name << " is cloned " << "with grade " << _grade << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &original)
{
	if (this == &original)
		return (*this);
	_grade = original._grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
	std::cout << "Grade incremented successfully" << std::endl;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
	std::cout << "Grade decremented successfully" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}