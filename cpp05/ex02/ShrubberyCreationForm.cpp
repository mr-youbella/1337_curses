/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:45:28 by youbella          #+#    #+#             */
/*   Updated: 2026/01/01 18:05:49 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation", 145, 137)
{
	std::cout << "Default Shrubbery Creation constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery Creation", 145, 137), target(target)
{
	std::cout << "Default Shrubbery Creation constructor params called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target)
{
	std::cout << "Copy Shrubbery Creation constructor called\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "Copy Shrubbery Creation assignment operator called\n";
	AForm::operator=(other);
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	const std::string name_file = target + "_shrubbery";
	std::ofstream	outfile(name_file.c_str());
	if (outfile.is_open())
	{
		outfile << "       _-_" << '\n';
		outfile << "    /~~   ~~\\" << '\n';
		outfile << " /~~         ~~\\" << '\n';
		outfile << "{               }" << '\n';
		outfile << " \\  _-     -_  /" << '\n';
		outfile << "   ~  \\\\ //  ~" << '\n';
		outfile << "_- -   | | _- _" << '\n';
		outfile << "  _ -  | |   -_" << '\n';
		outfile << "      // \\\\" << '\n';
		outfile.close();
		std::cout << "Shrubbery created in " << target << "_shrubbery" << '\n';
	}
	else
		std::cout << "Error: Could not create file." << '\n';
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Shrubbery Creation Destructor called\n";
}
