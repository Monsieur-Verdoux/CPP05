/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 00:15:46 by akovalev          #+#    #+#             */
/*   Updated: 2025/01/15 00:15:46 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std :: cout << "RobotomyRequestForm for " << _target << " is shredded" << std :: endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &original) : AForm(original)
{
	_target = original._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &original)
{
	if (this == &original)
		return (*this);
	_target = original._target;
	return (*this);
}

void RobotomyRequestForm::performExecution() const
{
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // use current time as seed for random generator otherwise it will generate the same number every time
	std::cout << "Drilling noises \"DRRRRRRRRRRRRRRRRRRRRRRRRRR\"" << std::endl;
	if ((std::rand() % 2 )== 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomization of " << _target << " has failed" << std::endl;
}


