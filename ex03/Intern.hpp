/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:56:48 by akovalev          #+#    #+#             */
/*   Updated: 2025/01/15 19:56:48 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <exception>
# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm *createShrubberyCreationForm(std::string target);
		AForm *createRobotomyRequestForm(std::string target);
		AForm *createPresidentialPardonForm(std::string target);
	public:
		Intern();
		~Intern();
		Intern(const Intern &original);
		
		Intern &operator=(const Intern &original);

		AForm *makeForm(std::string formName, std::string target);
		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char *what() const noexcept override;
		};
};

#endif