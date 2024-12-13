/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:35:32 by shinckel          #+#    #+#             */
/*   Updated: 2024/11/26 19:43:59 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"

int main(void) {
    Bureaucrat a("Regular Bureau", 5);
    a.increment();
    std::cout << a << std::endl;
    // exception won't be caught, leading to program termination (core dumped)
    // Bureaucrat b("Out of try catch Bureau", 0);
    // std::cout << b << std::endl;
    for (int i = -1; i < 10; i++) {
        try {
            Bureaucrat* b = new Bureaucrat("Bureau", i * 20);
            b->decrement();
            std::cout << *b << std::endl;
            delete b; // delete the dynamic allocated object
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}
