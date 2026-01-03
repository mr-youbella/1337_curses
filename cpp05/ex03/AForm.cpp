/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 12:20:57 by youbella          #+#    #+#             */
/*   Updated: 2025/12/31 16:30:16 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): name("default"), is_signed(false), grade_to_sign(13), grade_to_execute(37)
{
	std::cout << "Default AForm constructor called\n";
}

AForm::AForm(const std::string name, const int grade_to_sign, const int grade_to_execute): name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw AForm::GradeTooHighException();
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw AForm::GradeTooLowException();
	std::cout << "Name AForm constructor called\n";
}

AForm::AForm(const AForm &other): name(other.name), is_signed(other.is_signed), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
	std::cout << "Copy AForm constructor called\n";
}

AForm	&AForm::operator=(const AForm &other)
{
	std::cout << "Copy AForm assignment operator called\n";
	if (this != &other)
		is_signed = other.is_signed;
	return (*this);
}

const std::string	AForm::getName(void) const
{
	return (name);
}

bool				AForm::getIsSigned(void) const
{
	return (is_signed);
}

int					AForm::getGradeToSign(void) const
{
	return (grade_to_sign);
}

int					AForm::getGradeToExecute(void) const
{
	return (grade_to_execute);
}

void				AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= grade_to_sign)
		is_signed = true;
	else
		throw AForm::GradeTooLowException();
	
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed yet!";
}

AForm::~AForm(void)
{
	std::cout << "AForm Destructor called\n";
}

std::ostream &operator<<(std::ostream &os, const AForm &aform)
{
	os << aform.getName() << ", status: " << (aform.getIsSigned() ? "signed" : "not signed") << ", grade to sign: " << aform.getGradeToSign() << ", grade to execute: " << aform.getGradeToExecute() << ".\n";
	return (os);
}
