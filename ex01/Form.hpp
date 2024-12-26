/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:46:04 by akovalev          #+#    #+#             */
/*   Updated: 2024/12/27 00:46:04 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
	private :
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public :
		Form();
		~Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form &original);
		
		Form &operator=(const Form &original);

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &bur);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const noexcept override;
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const noexcept override;
		};
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif