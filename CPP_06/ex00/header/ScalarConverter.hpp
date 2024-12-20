/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:06:06 by shinckel          #+#    #+#             */
/*   Updated: 2024/12/20 16:16:33 by shinckel         ###   ########.fr       */
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

// The goal is to convert a string representation of a literal
// into different scalar types and handle various edge cases
// such as non-displayable characters and special floating-point values
class ScalarConverter {
  public:
    // Static method to convert the string literal
    static void converter(const std::string &literal);

  private:
    // Private constructor to prevent instantiation
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &clone);
    ScalarConverter &operator=(const ScalarConverter &clone);

    // Static methods for conversion
    static void convertChar(const std::string &literal);
    static void convertInt(const std::string &literal);
    static void convertFloat(const std::string &literal);
    static void convertDouble(const std::string &literal);
};

#endif