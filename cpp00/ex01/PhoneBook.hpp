/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:14:42 by youbella          #+#    #+#             */
/*   Updated: 2025/09/03 14:54:16 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "header.hpp"
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int		i;
		int		number_contact;
	public:
		PhoneBook();
		void	add(Contact &c);
		void	ShowAllContact(void);
};

#endif
