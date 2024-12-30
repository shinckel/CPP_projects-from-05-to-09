/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 03:35:20 by shinckel          #+#    #+#             */
/*   Updated: 2024/12/30 04:02:53 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &clone) { (void)clone; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &clone) { (void)clone; return *this; }

// Function to print the conversion results
void ScalarConverter::print(char c, int i, float f, double d) {
    std::cout << "char: ";
    if (std::isprint(c)) {
        std::cout << "'" << c << "'" << std::endl;
    } else {
        std::cout << "Non displayable" << std::endl;
    }
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

DataType ScalarConverter::determineDataType(const std::string &literal) {
    if (literal == "nan" || literal == "nanf" || literal == "-inff" || literal == "+inff" || literal == "-inf" || literal == "+inf") {
        return SPECIAL;
    } else if (literal.length() == 1 && !std::isdigit(literal[0])) {
        return CHAR;
    } else if (literal.find('.') != std::string::npos || literal.find('f') != std::string::npos) {
        return FLOAT;
    } else {
        try {
            ScalarConverter::convertTo<int>(literal);
            return INT;
        } catch (...) {
            try {
                ScalarConverter::convertTo<double>(literal);
                return DOUBLE;
            } catch (...) {
                return INVALID;
            }
        }
    }
}

void ScalarConverter::convertChar(const std::string &literal) {
    char c = literal[0];
    print(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c));
}

void ScalarConverter::convertInt(const std::string &literal) {
    double doubleValue = ScalarConverter::convertTo<double>(literal);
    if (doubleValue < std::numeric_limits<int>::min() || doubleValue > std::numeric_limits<int>::max()) {
        throw std::out_of_range("out of range");
    }
    int value = static_cast<int>(doubleValue);
    char c = (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max() && std::isprint(static_cast<char>(value))) ? static_cast<char>(value) : 0;
    print(c, value, static_cast<float>(value), static_cast<double>(value));
}

void ScalarConverter::convertFloat(const std::string &literal) {
    std::string floatLiteral = literal;
    if (floatLiteral[floatLiteral.length() - 1] == 'f') {
        floatLiteral = floatLiteral.substr(0, floatLiteral.length() - 1);
    }
    double value = ScalarConverter::convertTo<double>(floatLiteral);
    if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max()) {
        throw std::out_of_range("out of range");
    }
    char c = (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max() && std::isprint(static_cast<char>(value))) ? static_cast<char>(value) : 0;
    print(c, static_cast<int>(value), static_cast<float>(value), value);
}

void ScalarConverter::convertDouble(const std::string &literal) {
    double value = ScalarConverter::convertTo<double>(literal);
    char c = (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max() && std::isprint(static_cast<char>(value))) ? static_cast<char>(value) : 0;
    print(c, static_cast<int>(value), static_cast<float>(value), value);
}

void ScalarConverter::convertSpecial(const std::string &literal) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (literal == "nan" || literal == "nanf") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } else {
        std::string infLiteral = literal;
        if (infLiteral[infLiteral.length() - 1] == 'f') {
            infLiteral = infLiteral.substr(0, infLiteral.length() - 1);
        }
        std::cout << "float: " << infLiteral << "f" << std::endl;
        std::cout << "double: " << infLiteral << std::endl;
    }
}

void ScalarConverter::converter(const std::string &literal) {
    DataType type = determineDataType(literal);
    try {
        switch (type) {
            case CHAR:
                convertChar(literal);
                break;
            case INT:
               convertInt(literal);
                break;
            case FLOAT:
                convertFloat(literal);
                break;
            case DOUBLE:
                convertDouble(literal);
                break;
            case SPECIAL:
                convertSpecial(literal);
                break;
            case INVALID:
            default:
                std::cout << "invalid argument" << std::endl;
                break;
        }
    } catch (const std::out_of_range& e) {
        std::cout << "out of range: " << e.what() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "invalid argument: " << e.what() << std::endl;
    }
}
