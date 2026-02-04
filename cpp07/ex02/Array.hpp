/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 09:27:44 by youbella          #+#    #+#             */
/*   Updated: 2026/02/02 09:32:12 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>

	class Array
	{
		private:
			T				*_data;
			unsigned int	_size;
	
		public:
			Array() : _data(NULL), _size(0)
			{
				std::cout << "Default constructor\n";
			}

			Array(unsigned int n) : _data(new T[n]()), _size(n)
			{
				std::cout << "Default constructor by params\n";
			}
	
			Array(const Array &other) : _data(NULL), _size(0)
			{
				std::cout << "Copy constructor\n";
				*this = other;
			}
	
			Array			&operator=(const Array &other)
			{
				std::cout << "Copy assignment constructor\n";
				if (this != &other)
				{
					delete[] _data;
					_size = other._size;
					_data = new T[_size];
					for (unsigned int i = 0; i < _size; i++)
						_data[i] = other._data[i];
				}
				return (*this);
			}

			unsigned int	size() const
			{
				return _size;
			}

			class OutOfBounds : public std::exception
			{
				public:
					virtual const char *what() const throw()
					{
						return "Out of bounds";
					}
			};

			T				&operator[](int index)
			{
				if (index < 0 || index >= (int)_size)
					throw OutOfBounds();
				return _data[index];
			}

			const T			&operator[](int index) const
			{
				if (index < 0 || index >= (int)_size)
					throw OutOfBounds();
				return _data[index];
			}

			~Array()
			{
				std::cout << "destructor\n";
				delete[] _data;
			}
	};

#endif
