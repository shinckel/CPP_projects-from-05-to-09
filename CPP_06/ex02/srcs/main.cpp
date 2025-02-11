/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:25:37 by shinckel          #+#    #+#             */
/*   Updated: 2025/02/11 18:38:58 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/A.hpp"
#include "../header/Base.hpp"

// implement a base class and derived classes
// create functions to identify the type of the derived class instances at runtime
int main(void) {
    Base*   basePtr = generate();
    identify(basePtr);
    identify(*basePtr);

    A a;
    identify(a);

    Base    d;
    identify(d);

    delete  basePtr;
    return 0;
}