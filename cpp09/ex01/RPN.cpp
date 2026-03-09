/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 04:10:17 by youbella          #+#    #+#             */
/*   Updated: 2026/03/09 19:54:16 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

void RPN::evaluate(const std::string &expression)
{
	std::istringstream	iss(expression);
	std::string			token;
	while (iss >> token)
	{
		if (token.size() == 1 && std::isdigit(token[0]))
			_stack.push(token[0] - '0');
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (_stack.size() < 2)
			{
				std::cerr << "Error\n";
				return ;
			}
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			if (token == "+")
				_stack.push(a + b);
			else if (token == "-")
				_stack.push(a - b);
			else if (token == "*")
				_stack.push(a * b);
			else if (token == "/")
			{
				if (b == 0)
				{
					std::cerr << "Error\n";
					return ;
				}
				_stack.push(a / b);
			}
		}
		else
		{
			std::cerr << "Error\n";
			return ;
		}
	}
	if (_stack.size() != 1)
	{
		std::cerr << "Error\n";
		return ;
	}
	std::cout << _stack.top() << '\n';
}

RPN::~RPN() {}
