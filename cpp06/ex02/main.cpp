/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <younesoubllal@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 08:55:31 by youbella          #+#    #+#             */
/*   Updated: 2026/01/29 18:47:50 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

int main()
{
    Base* p = generate();

    std::cout << "identify(ptr): ";
    identify(p);

    std::cout << "identify(ref): ";
    identify(*p);

    delete p;
    return 0;
}