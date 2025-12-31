/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:45:17 by youbella          #+#    #+#             */
/*   Updated: 2025/12/31 16:24:02 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("Robotomy Request", 72, 45)
{
	std::cout << "Default Robotomy Request constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request", 72, 45), target(target)
{
	std::cout << "Default Robotomy Request constructor params called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), target(other.target)
{
	std::cout << "Copy Robotomy Request constructor called\n";
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "Copy Robotomy Request assignment operator called\n";
	(void)other;
	return (*this);
}

void				RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();   
	std::cout << "* VRRRRRR... DRILLING NOISES... *" << '\n';
	if (std::rand() % 2 == 0)
		std::cout << target << " has been robotomized successfully!" << '\n';
	else
		std::cout << "The robotomy on " << target << " failed." << '\n';
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Robotomy Request Destructor called\n";
}
