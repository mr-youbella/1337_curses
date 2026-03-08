/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 00:26:39 by youbella          #+#    #+#             */
/*   Updated: 2026/03/08 01:20:35 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <exception>
# include <stdexcept>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _storage;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		void addNumber(int number);
		template <typename T>
			void addRange(T begin, T end)
			{
				if (_storage.size() + std::distance(begin, end) > _n)
					throw std::out_of_range("Span is full");
				_storage.insert(_storage.end(), begin, end);
			}
		long shortestSpan();
		long longestSpan();
		class FullException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class NoSpanException : public std::exception
		{
			virtual const char* what() const throw();
		};
		~Span();
};

#endif
