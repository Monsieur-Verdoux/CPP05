/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 00:11:51 by akovalev          #+#    #+#             */
/*   Updated: 2025/01/15 00:11:51 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Defaultform"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "A default form is printed" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << "A form " << _name << " is printed" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm " << _name << " is shredded" << std::endl;
}

AForm::AForm(const AForm &original) : _name(original._name), _isSigned(original._isSigned), _gradeToSign(original._gradeToSign), _gradeToExecute(original._gradeToExecute)
{
	std::cout << "A form " << _name << " is copied" << std::endl;
}

AForm &AForm::operator=(const AForm &original)
{
	if (this == &original)
		return (*this);
	_isSigned = original._isSigned;
	return (*this);
}

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getIsSigned() const
{
	return (_isSigned);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!_isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
	performExecution();
}

const char *AForm::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low");
}

const char *AForm::FormNotSignedException::what() const noexcept
{
	return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	if (form.getIsSigned())
		out << "Form " << form.getName() << " is " << "signed" << std::endl;
	else
		out << "Form " << form.getName() << " is " << "not signed" << std::endl;
	out << "Grade to sign the form: " << form.getGradeToSign() << std::endl;
	out << "Grade to execute the form: " << form.getGradeToExecute() << std::endl;
	return (out);
}