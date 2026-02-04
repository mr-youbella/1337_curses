/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 08:12:34 by youbella          #+#    #+#             */
/*   Updated: 2026/02/02 08:21:35 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
	void	swap(T &x, T &y)
	{
		T temp = x;
		x = y;
		y = temp;
	}

template <typename T>
	T	const &max(const T & x, const T &y)
	{
		return (x > y ? x : y);
	}

template <typename T>
	T	const &min(const T &x, const T &y)
	{
		return (x < y ? x : y);
	}

#endif
