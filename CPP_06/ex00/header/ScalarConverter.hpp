/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:06:06 by shinckel          #+#    #+#             */
/*   Updated: 2025/02/09 20:12:49 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>
# include <limits>
# include <cstdlib>
# include <cmath>
# include <cctype>
# include <stdexcept>

// the goal is to convert a string representation of a literal
// into different scalar types and handle edge cases
// such as non-displayable characters / nan / +inf / -inf
class ScalarConverter {
  public:
    // static method to convert the string literal: no instantiation
    static void converter(const std::string &literal);

  private:
    // private constructor to prevent instantiation
    // Orthodox Canonical Form
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &clone);
    ScalarConverter &operator=(const ScalarConverter &clone);

    enum DataType {
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        SPECIAL,
        INVALID
    };

    struct ConversionResult {
        DataType    type;
        double      value;
    };

    // Static methods for conversion
    // they are often used for utility functions that perform common tasks
    static void convertSpecial(const std::string &literal);
    static void print(double num);
    static ConversionResult determineDataType(const std::string &literal);

    // avoid writing separate conversion functions for each data type
    template <typename T>
    static T convertTo(const std::string &literal) {
        std::stringstream ss(literal);
        T value;
        ss >> value;
        if (ss.fail() || !ss.eof()) {
            throw std::invalid_argument("invalid argument");
        }
        return value;
    }
};

#endif
