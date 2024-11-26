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
    try {
        Bureaucrat  b("John Doe", 10);
        b.decrement();
        std::cout << b << std::endl;

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;        
    }
    // Bureaucrat b("John Doe", 5);
    // std::cout << b << std::endl;
    return 0;
}
