/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 08:51:33 by youbella          #+#    #+#             */
/*   Updated: 2026/01/31 14:11:20 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <cerrno>
# include <climits> 

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter	&operator=(const ScalarConverter &other);
		~ScalarConverter();
	public:
		static void		convert(const std::string &literal);
};

#endif
