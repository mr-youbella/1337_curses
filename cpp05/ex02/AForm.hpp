/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 11:53:30 by youbella          #+#    #+#             */
/*   Updated: 2025/12/31 11:38:40 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				is_signed;
		const int			grade_to_sign;
		const int			grade_to_execute;
	public:
		AForm(void);
		AForm(const std::string name, const int grade_to_sign, const int grade_to_execute);
		AForm(const AForm &other);
		AForm				&operator=(const AForm &other);
		const std::string	getName(void) const;
		bool				getIsSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		void				beSigned(Bureaucrat &bureaucrat);
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		virtual void		execute(Bureaucrat const &executor) const = 0;
		virtual	~AForm(void);
};

std::ostream	&operator<<(std::ostream &os, AForm const &aform);

#endif
