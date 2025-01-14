/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 00:11:43 by akovalev          #+#    #+#             */
/*   Updated: 2025/01/15 00:11:43 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
	private :
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public :
		AForm();
		virtual ~AForm(); // needs to be virtual to ensure that the destructor of the derived class is called
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &original);
		
		AForm &operator=(const AForm &original);

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &bur);\

		void execute(Bureaucrat const & executor) const;
		virtual void performExecution() const = 0;

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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const noexcept override;
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif