/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:58:54 by akovalev          #+#    #+#             */
/*   Updated: 2024/12/27 00:58:54 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Defaultform"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "A default form is printed" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "A form " << _name << " is printed" << std::endl;
}

Form::~Form()
{
	std::cout << "Form " << _name << " is shredded" << std::endl;
}

Form::Form(const Form &original) : _name(original._name), _isSigned(original._isSigned), _gradeToSign(original._gradeToSign), _gradeToExecute(original._gradeToExecute)
{
	std::cout << "A form " << _name << " is copied" << std::endl;
}

Form &Form::operator=(const Form &original)
{
	if (this == &original)
		return (*this);
	_isSigned = original._isSigned;
	return (*this);
}

std::string Form::getName() const
{
	return (_name);
}

bool Form::getIsSigned() const
{
	return (_isSigned);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

const char *Form::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	if (form.getIsSigned())
		out << "Form " << form.getName() << " is " << "signed" << std::endl;
	else
		out << "Form " << form.getName() << " is " << "not signed" << std::endl;
	out << "Grade to sign the form: " << form.getGradeToSign() << std::endl;
	out << "Grade to execute the form: " << form.getGradeToExecute() << std::endl;
	return (out);
}