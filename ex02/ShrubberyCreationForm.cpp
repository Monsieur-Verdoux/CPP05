/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 00:13:32 by akovalev          #+#    #+#             */
/*   Updated: 2025/01/15 00:13:32 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = "Monty Python";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std :: cout << "ShrubberyCreationForm for " << _target << " is shredded" << std :: endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &original) : AForm(original)
{
	_target = original._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &original)
{
	if (this == &original)
		return (*this);
	_target = original._target;
	return (*this);
}

void ShrubberyCreationForm::performExecution() const 
{
	std::ofstream file;
	file.open(_target + "_shrubbery");
	std:: string tree =  "              * *    \n"
        "           *    *  *\n"
        "      *  *    *     *  *\n"
        "     *     *    *  *    *\n"
        " * *   *    *    *    *   *\n"
        " *     *  *    * * .#  *   *\n"
        " *   *     * #.  .# *   *\n"
        "  *     \"#.  #: #\" * *    *\n"
        " *   * * \"#. ##\"       *\n"
        "   *       \"###\n"
        "             \"##\n"
        "              ##.\n"
        "              .##:\n"
        "              :###\n"
        "              ;###\n"
        "            ,####.\n"
        "            .######.\n";
	if (file.is_open())
		file << tree;
	else 
		std::cerr << "Error: could not open file" << std::endl;
	file.close();
}