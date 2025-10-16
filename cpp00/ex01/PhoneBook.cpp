/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:14:42 by youbella          #+#    #+#             */
/*   Updated: 2025/09/03 14:54:40 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

short	is_numeric(std::string str)
{
	size_t	i;

	i = 0;
	while (i < str.size())
	{
		if (!std::isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

PhoneBook::PhoneBook()
{
	i = 0;
	number_contact = 0;
}

void	PhoneBook::add(Contact &c)
{
	if (number_contact < 8)
		number_contact++;
	contacts[i] = c;
	i = (i + 1) % 8; 
}

void PhoneBook::ShowAllContact(void)
{
	int			j;
	std::string	index;
	int			int_index;
	size_t		width;
	std::string	f_name;
	std::string	l_name;
	std::string	n_name;
	std::string	phone_number;
	std::string	darkest_secret;
	j = 0;
	width = 11;
	std::cout << BLUE << "======================================================\n" << DEF;
	std::cout << BLUE << "| " << GREEN << std::setw(width) << "INDEX" << DEF;
	std::cout << BLUE << "| " << GREEN << std::setw(width) << "First Name" << DEF;
	std::cout << BLUE << "| " << GREEN << std::setw(width) << "Last Name" << DEF;
	std::cout << BLUE << "| " << GREEN << std::setw(width) << "Nickname" << DEF;
	std::cout << BLUE << " |\n" << DEF;
	std::cout << BLUE << "======================================================\n" << DEF;
    while (j < number_contact)
    {
		f_name = contacts[j].getFirstName();
		l_name = contacts[j].getLastName();
		n_name = contacts[j].getNickName();
		if (f_name.length() > width - 1)
			f_name = f_name.substr(0, width - 1) + ".";
		if (l_name.length() > width - 1)
			l_name = l_name.substr(0, width - 1) + ".";
		if (n_name.length() > width - 1)
			n_name = n_name.substr(0, width - 1) + ".";
		std::cout << BLUE << "| " << DEF << std::setw(width) << j + 1;
		std::cout << BLUE << "| " << DEF << std::setw(width) << f_name;
		std::cout << BLUE << "| " << DEF << std::setw(width) << l_name;
		std::cout << BLUE << "| " << DEF << std::setw(width) << n_name;
		std::cout << BLUE << " |\n" << DEF;
		j++;
		if (j != number_contact)
			std::cout << BLUE << "------------------------------------------------------\n" << DEF;
    }
	if (!number_contact)
	{
		std::cout << RED << "| No Data\n" << DEF;
		std::cout << BLUE << "======================================================\n" << DEF;
		return ;
	}
    std::cout << BLUE << "======================================================\n" << DEF;
	std::cout << GREEN << "Select Index: " << DEF;
	std::cout << CYAN;
	std::getline(std::cin, index);
	std::cout << DEF;
	if (std::cin.eof())
		ft_exit();
	int_index = atoi(index.c_str());
	if (!is_numeric(index) || int_index <= 0 || int_index > number_contact)
	{
		std::cout << RED << "Index not valid\n" << DEF;
		return ;
	}
	std::cout << BLUE << "======================================================\n" << DEF;
	f_name = contacts[int_index - 1].getFirstName();
	l_name = contacts[int_index - 1].getLastName();
	n_name = contacts[int_index - 1].getNickName();
	phone_number = contacts[int_index - 1].getPhoneNumber();
	darkest_secret = contacts[int_index - 1].getDarkestSecret();
	std::cout << "First Name: " << f_name << '\n';
	std::cout << "Last Name: " << l_name << '\n';
	std::cout << "NickName: " << n_name << '\n';
	std::cout << "Phone Number: " << phone_number << '\n';
	std::cout << "Darkest Secret: " << darkest_secret << '\n';
    std::cout << BLUE << "=========================================================\n" << DEF;
}
