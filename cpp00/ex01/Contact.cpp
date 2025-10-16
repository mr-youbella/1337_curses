/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:06:49 by youbella          #+#    #+#             */
/*   Updated: 2025/09/03 14:47:17 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setFirstName(std::string &f_name)
{
	first_name = f_name;
}

void	Contact::setLastName(std::string &l_name)
{
	last_name = l_name;
}

void	Contact::setNickName(std::string &n_name)
{
	nickname = n_name;
}

void	Contact::setPhoneNumber(std::string &p_number)
{
	phone_number = p_number;
}

void	Contact::setDarkestSecret(std::string &d_secret)
{
	darkest_secret = d_secret;
}

std::string	Contact::getFirstName(void)
{
	return (first_name);
}

std::string	Contact::getLastName(void)
{
	return (last_name);
}

std::string	Contact::getNickName(void)
{
	return (nickname);
}

std::string	Contact::getPhoneNumber(void)
{
	return (phone_number);
}

std::string	Contact::getDarkestSecret(void)
{
	return (darkest_secret);
}
