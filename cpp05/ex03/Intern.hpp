/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:54:10 by youbella          #+#    #+#             */
/*   Updated: 2026/01/03 17:18:57 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_HPP
# define Intern_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &other);
		Intern 	&operator=(const Intern &other);
		AForm	*makeForm(std::string form_name, std::string target);
		class InternCreate: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		~Intern(void);
};

#endif
