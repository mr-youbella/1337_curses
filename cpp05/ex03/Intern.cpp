/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:54:10 by youbella          #+#    #+#             */
/*   Updated: 2026/01/03 17:26:20 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Default Intern constructor called\n";
}

Intern::Intern(const Intern &other)
{
	std::cout << "Copy Intern constructor called\n";
	(void)other;
}

Intern	&Intern::operator=(const Intern &other)
{
	std::cout << "Copy Intern assignment operator called\n";
	(void)other;
	return (*this);
}

AForm	*Intern::makeForm(std::string form_name, std::string target)
{
	std::string	names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (form_name == names[i])
		{
			std::cout << "Intern creates " << form_name << '\n';
			switch (i)
			{
				case 0:	return (new ShrubberyCreationForm(target));
				case 1:	return (new RobotomyRequestForm(target));
				case 2:	return (new PresidentialPardonForm(target));
			}
		}
	}
	throw Intern::InternCreate();
	return (NULL);
}

const char	*Intern::InternCreate::what() const throw()
{
	return ("Error: Intern cannot create!");
}

Intern::~Intern(void)
{
	std::cout << "Intern Destructor called\n";
}
