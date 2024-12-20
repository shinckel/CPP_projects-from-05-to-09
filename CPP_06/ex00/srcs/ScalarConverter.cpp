/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:06:09 by shinckel          #+#    #+#             */
/*   Updated: 2024/12/20 16:20:55 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &clone) { (void)clone; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &clone) { (void)clone; return *this; }

void ScalarConverter::converter(const std::string &literal) {
    convertChar(literal);
    convertInt(literal);
    convertFloat(literal);
    convertDouble(literal);
}

void ScalarConverter::convertChar(const std::string &literal) {
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        // Handle single character input
        char c = literal[0];
        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    } else {
        try {
            int value = std::atoi(literal.c_str());
            if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
                throw std::out_of_range("out of char range");
            char c = static_cast<char>(value);
            if (std::isprint(c))
                std::cout << "char: '" << c << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        } catch (...) {
            std::cout << "char: impossible" << std::endl;
        }
    }
}

void ScalarConverter::convertInt(const std::string &literal) {
    try {
        int value = std::atoi(literal.c_str()); // Use .c_str() to convert std::string to const char*
        std::cout << "int: " << value << std::endl;
    } catch (...) {
        std::cout << "int: impossible" << std::endl;
    }
}

void ScalarConverter::convertFloat(const std::string &literal) {
    try {
        float value = std::atof(literal.c_str()); // Use .c_str() to convert std::string to const char*
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << value << "f" << std::endl;
    } catch (...) {
        std::cout << "float: impossible" << std::endl;
    }
}

void ScalarConverter::convertDouble(const std::string &literal) {
    try {
        double value = std::strtod(literal.c_str(), 0);
        std::cout << "double: " << value << std::endl;
    } catch (...) {
        std::cout << "double: impossible" << std::endl;
    }
}
