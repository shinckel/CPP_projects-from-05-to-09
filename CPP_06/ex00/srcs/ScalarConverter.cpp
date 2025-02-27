/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:28:09 by shinckel          #+#    #+#             */
/*   Updated: 2025/02/27 09:48:39 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &clone) { (void)clone; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &clone) { (void)clone; return *this; }

void ScalarConverter::print(double num) {
    (num >= std::numeric_limits<char>::min() && num <= std::numeric_limits<char>::max() && std::isprint(num)) ?
        std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl :
        std::cout << "char: non displayable" << std::endl;
    (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max()) ?
        std::cout << "int: out of range" << std::endl :
        std::cout << "int: " << static_cast<int>(num) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    (num <= -std::numeric_limits<float>::max() || num >= std::numeric_limits<float>::max()) ?
        std::cout << "float: out of range" << std::endl :
        std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
    (num <= -std::numeric_limits<double>::max() || num >= std::numeric_limits<double>::max()) ?
        std::cout << "double: out of range" << std::endl :
        std::cout << "double: " << static_cast<double>(num) << std::endl;
}

// if the character '.' and 'f' is not found, find returns std::string::npos... otherwise, return substr index position
// checking literal.length() > 2 is necessary, otherwise ".f" will be understood as valid arg 
ScalarConverter::ConversionResult ScalarConverter::determineDataType(const std::string &literal) {
    ConversionResult result;
    if (literal == "nan" || literal == "nanf" || literal == "-inff" \
        || literal == "+inff" || literal == "-inf" || literal == "+inf") {
        result.type = SPECIAL;
        result.value = std::numeric_limits<double>::quiet_NaN();
    } else if (literal.length() == 1 && !std::isdigit(literal[0])) {
        result.type = CHAR;
        result.value = literal[0];
    } else if (literal.find('.') != std::string::npos && literal.find('f') != std::string::npos \
        && (literal.find('f') == literal.size() - 1) && literal.length() > 2) {
        std::string floatLiteral = literal;
        if (floatLiteral[floatLiteral.length() - 1] == 'f')
            floatLiteral = floatLiteral.substr(0, floatLiteral.length() - 1);
        try {
            result.value = ScalarConverter::convertTo<float>(floatLiteral);
            result.type = FLOAT;
        } catch(...) {
            return determineDataType(floatLiteral); // recursivelly, check again now trying other number formats
        }
    } else {
        try {
            result.value = convertTo<int>(literal);
            result.type = INT;
        } catch (...) {
            try {
                result.value = convertTo<double>(literal);
                result.type = DOUBLE;
            } catch (...) {
                result.type = INVALID;
                result.value = 0.0;
            }
        }
    }
    return result;
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
    ConversionResult result = determineDataType(literal);
    switch (result.type) {
        case CHAR:
        case INT:
        case FLOAT:
        case DOUBLE:
            print(result.value);
            break;
        case SPECIAL:
            convertSpecial(literal);
            break;
        case INVALID:
        default:
            std::cout << "invalid argument" << std::endl;
            break;
    }
}