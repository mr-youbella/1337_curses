/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:09:21 by youbella          #+#    #+#             */
/*   Updated: 2025/09/03 14:34:11 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void	ft_exit(void)
{
	std::cout << RED << "\nexit\n" << DEF;
	exit(0);
}

short	is_empty(std::string str)
{
	size_t	i;

	i = 0;
	while (i < str.size())
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	get_data(std::string &first_name, std::string &last_name, std::string &nickname, std::string &phone_number, std::string &darkest_secret)
{
	while (1)
	{
		std::cout << YELLOW << "First Name: " << DEF;
		std::cout << CYAN;
		std::getline(std::cin, first_name);
		std::cout << DEF;
		if (std::cin.eof())
			ft_exit();
		if (!first_name.size() || is_empty(first_name))
		{
			std::cout << RED << "Input can't be empty!\n" << DEF;
			continue ;
		}
		break ;
	}
	while (1)
	{
		std::cout << YELLOW << "Last Name: " << DEF;
		std::cout << CYAN;
		std::getline(std::cin, last_name);
		std::cout << DEF;
		if (std::cin.eof())
			ft_exit();
		if (!last_name.size() || is_empty(last_name))
		{
			std::cout << RED << "Input can't be empty!\n" << DEF;
			continue ;
		}
		break ;
	}
	while (1)
	{
		std::cout << YELLOW << "NickName: " << DEF;
		std::cout << CYAN;
		std::getline(std::cin, nickname);
		std::cout << DEF;
		if (std::cin.eof())
			ft_exit();
		if (!nickname.size() || is_empty(nickname))
		{
			std::cout << RED << "Input can't be empty!\n" << DEF;
			continue ;
		}
		break ;
	}
	while (1)
	{
		std::cout << YELLOW << "Phone Number: " << DEF;
		std::cout << CYAN;
		std::getline(std::cin, phone_number);
		std::cout << DEF;
		if (std::cin.eof())
			ft_exit();
		if (!phone_number.size() || is_empty(phone_number))
		{
			std::cout << RED << "Input can't be empty!\n" << DEF;
			continue ;
		}
		break ;
	}
	while (1)
	{
		std::cout << YELLOW << "Darkest Secret: " << DEF;
		std::cout << CYAN;
		std::getline(std::cin, darkest_secret);
		std::cout << DEF;
		if (std::cin.eof())
			ft_exit();
		if (!darkest_secret.size() || is_empty(darkest_secret))
		{
			std::cout << RED << "Input can't be empty!\n" << DEF;
			continue ;
		}
		break ;
	}
}

int	main()
{
	PhoneBook	phone_book;
	Contact		new_contact;
	std::string	command;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	while (1)
	{
		std::cout << CYAN << "====================[ PhoneBook ]====================\n" << DEF;
		std::cout << GREEN << "Please Enter command [ADD - SEARCH - EXIT]: " << DEF;
		std::cout << CYAN;
		std::getline(std::cin, command);
		std::cout << DEF;
		if (std::cin.eof())
			ft_exit();
		if (command == "ADD")
		{
			get_data(first_name, last_name, nickname, phone_number, darkest_secret);
			new_contact.setFirstName(first_name);
			new_contact.setLastName(last_name);
			new_contact.setNickName(nickname);
			new_contact.setPhoneNumber(phone_number);
			new_contact.setDarkestSecret(darkest_secret);
			phone_book.add(new_contact);
		}
		else if (command == "SEARCH")
			phone_book.ShowAllContact();
		else if (command == "EXIT")
			ft_exit();
		else
			std::cout << RED << "Command Not Found\n" << DEF;
	}
}
