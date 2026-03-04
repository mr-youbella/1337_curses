/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 21:45:15 by youbella          #+#    #+#             */
/*   Updated: 2026/03/04 21:49:28 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Element not found in container";
		}
};

template <typename T>
	typename T::iterator easyfind(T &container, int to_find)
	{
		typename T::iterator it = std::find(container.begin(), container.end(), to_find);
		if (it == container.end())
		{
			throw NotFoundException();
		}
		return (it);
	}

#endif
