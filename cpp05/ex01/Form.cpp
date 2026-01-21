/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 12:20:57 by youbella          #+#    #+#             */
/*   Updated: 2026/01/21 10:13:29 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): name("default"), is_signed(false), grade_to_sign(13), grade_to_execute(37)
{
	std::cout << "Default Form constructor called\n";
}

Form::Form(const std::string name, const int grade_to_sign, const int grade_to_execute): name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw Form::GradeTooHighException();
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw Form::GradeTooLowException();
	std::cout << "Name Form constructor called\n";
}

Form::Form(const Form &other): name(other.name), is_signed(other.is_signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
	std::cout << "Copy Form constructor called\n";
}

Form	&Form::operator=(const Form &other)
{
	std::cout << "Copy Form assignment operator called\n";
	if (this != &other)
		is_signed = other.is_signed;
	return (*this);
}

const std::string	Form::getName(void) const
{
	return (name);
}

bool				Form::getIsSigned(void) const
{
	return (is_signed);
}

int					Form::getGradeToSign(void) const
{
	return (grade_to_sign);
}

int					Form::getGradeToExecute(void) const
{
	return (grade_to_execute);
}

void				Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= grade_to_sign)
		is_signed = true;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

Form::~Form(void)
{
	std::cout << "Form Destructor called\n";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << form.getName() << ", status: " << (form.getIsSigned() ? "signed" : "not signed") << ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute() << ".\n";
	return (os);
}
