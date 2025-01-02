/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:25:37 by shinckel          #+#    #+#             */
/*   Updated: 2025/01/02 15:01:02 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Base.hpp"

// implement a base class and derived classes
// create functions to identify the type of the derived class instances at runtime

int main(void) {
    Base* basePtr = Base::generate();
    Base::identify(basePtr);
    Base::identify(*basePtr);

    std::cout << "name: " << basePtr->getName() << std::endl;
    std::cout << "pointer: " << &basePtr << std::endl;

    delete basePtr;
    return 0;
}