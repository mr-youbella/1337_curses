/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 08:55:31 by youbella          #+#    #+#             */
/*   Updated: 2026/03/02 15:29:41 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

int main()
{
    Base *p = generate();

    std::cout << "identify(ptr): ";
    identify(p);

    std::cout << "identify(ref): ";
    identify(*p);

    delete p;
    return (0);
}
