/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:21:50 by shinckel          #+#    #+#             */
/*   Updated: 2025/01/27 11:22:09 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream> // file stream classes
# include <sstream>
# include <string>
# include <map>
# include <iomanip> // std::setprecision
# include <cstring> // strcmp
# include <cctype> // isdigit
# include <cstdlib> // atoi

// container choise: std::map, it allows efficient key-based lookups
class BitcoinExchange {
  public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &clone);
    BitcoinExchange &operator=(const BitcoinExchange &clone);
    ~BitcoinExchange();

    // function pointer type — my approch it to abstract the process of opening and first checks
    typedef void (*LineProcessor)(const std::string&, BitcoinExchange&);
    void readingStreams(const std::string &file, LineProcessor processor);
    void mapData(const std::string &file);
    // they must be static — the class was not instantiated in its scope
    // otherwise: error: invalid use of non-static member function
    // option: lambda functions?
    static void loadDatabase(const std::string &line, BitcoinExchange &instance);
    static void processInputFile(const std::string &line, BitcoinExchange &instance);
    std::map<std::string, double>::const_iterator isValidDate(const std::string &date) const;
    void  isValidValue(double &value) const;
    struct  WrongFormat;
    struct  OutOfBoundsValue;

  private:
    std::map<std::string, double> bitcoinPrices;
};

#endif