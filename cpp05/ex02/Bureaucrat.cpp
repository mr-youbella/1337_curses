/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 12:20:57 by youbella          #+#    #+#             */
/*   Updated: 2025/12/31 11:50:17 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): name("default"), grade(13)
{
	std::cout << "Default constructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
	std::cout << "Name constructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.name)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		grade = other.grade;
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (name);
}

int			Bureaucrat::getGrade(void) const
{
	return (grade);
}

void		Bureaucrat::incrementGrade()
{
	if (grade == 1)
		throw GradeTooHighException();
	else
		grade--;
}

void		Bureaucrat::decrementGrade()
{
	if (grade == 150)
		throw GradeTooLowException();
	else
		grade++;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

void		Bureaucrat::executeForm(const AForm &form)
{
    try
	{
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
	catch (std::exception &e) {
        std::cout << name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called\n";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
    return (os);
}
