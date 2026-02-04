/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 08:12:34 by youbella          #+#    #+#             */
/*   Updated: 2026/02/02 10:05:08 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T>

	void	iter(T *arr, size_t len, void (*f)(T &))
	{
		for (size_t i = 0; i < len; ++i)
			f(arr[i]);
	}

template <typename T>
	void	iter(const T *arr, size_t len, void (*f)(T const &))
	{
		for (size_t i = 0; i < len; ++i)
			f(arr[i]);
	}

#endif
