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
	std::cout << "Bureaucrat " << _name << " is born " << "with grade " << _grade << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " perishes" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &original) : _name(original._name), _grade(original._grade)
{
	std::cout << "Bureaucrat " << _name << " is cloned " << "with grade " << _grade << std::endl;
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

void Bureaucrat::signForm(AForm &form)
{
	if (form.getIsSigned())
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because it was already signed" << std::endl;
		return ;
	}
	else if (form.getGradeToSign() < _grade)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because their grade was too low" << std::endl;
		return ;
	}
	else 
	{
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	if (form.getIsSigned())
	{
		if (form.getGradeToExecute() < _grade)
		{
			std::cout << _name << " couldn't execute " << form.getName() << " because their grade was too low" << std::endl;
			return ;
		}
		else
		{
			form.execute(*this);
			std::cout << _name << " executes " << form.getName() << std::endl;
		}
	}
	else
	{
		std::cout << _name << " couldn't execute " << form.getName() << " because it was not signed" << std::endl;
	}
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