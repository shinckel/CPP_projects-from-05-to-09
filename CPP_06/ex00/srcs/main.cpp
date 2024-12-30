/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:06:03 by shinckel          #+#    #+#             */
/*   Updated: 2024/12/30 02:58:46 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ScalarConverter.hpp"

/*
42 / 42.42 / 42.0f / nan / +inf / -inf / A / * / hello
*/

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }
    try {
        ScalarConverter::converter(argv[1]);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}