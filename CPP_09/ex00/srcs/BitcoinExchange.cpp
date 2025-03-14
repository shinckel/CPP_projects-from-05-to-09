/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:21:28 by shinckel          #+#    #+#             */
/*   Updated: 2025/02/27 09:27:03 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};
BitcoinExchange::~BitcoinExchange() {};
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &clone) { *this = clone; return *this; }
BitcoinExchange::BitcoinExchange(const BitcoinExchange &clone) { *this = clone; }

struct  BitcoinExchange::WrongDateFormat : public std::exception {
  const char* what() const throw() {
    return "\033[1;41m WrongDateFormat \033[0m — Please enter a valid date format YYYY-MM-DD";
  }
};

struct  BitcoinExchange::WrongInputFormat : public std::exception {
  const char* what() const throw() {
    return "\033[1;41m WrongInputFormat \033[0m — Please, enter a valid format in your input file <date | value>";
  }
};

// a valid value must be either a float or a positive integer, between 0 and 1000
struct  BitcoinExchange::OutOfBoundsValue : public std::exception {
  const char* what() const throw() {
    return "\033[1;41m OutOfBoundsValue \033[0m — Please, enter a positive integer between 0 and 1000 as value";
  }
};

// improve, don't use atoi
bool checkFormat(const std::string &date) {
  if (date.size() != 10 || date[4] != '-' || date[7] != '-')
    return false;

  int year = atoi(date.substr(0, 4).c_str());
  int month = atoi(date.substr(5, 2).c_str());
  int day = atoi(date.substr(8, 2).c_str());
  if (year < 1900 || month < 1 || month > 12 || day < 1 || day > 31)
    return false;
  if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    return false;
  if (month == 2) {
    bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (day > 29 || (day == 29 && !isLeapYear))
      return false;
  }
  return true;
}

// std::regex is only available in C++11
// std::regex datePattern(R"(\d{4}-\d{2}-\d{2})");
// return std::regex_match(date, datePattern);
std::map<std::string, double>::const_iterator BitcoinExchange::isValidDate(const std::string &date) const {
  if (!checkFormat(date))
    throw WrongDateFormat();
  // look for the date in the map
  std::map<std::string, double>::const_iterator it = bitcoinPrices.find(date);
  if (it != bitcoinPrices.end())
    return it;
  // if the date is not found, return the closest date
  it = bitcoinPrices.lower_bound(date);
  if (it == bitcoinPrices.begin())
    return bitcoinPrices.begin();
  --it; // move to the previous date
  return it;
}

/*
                    functionA()
                        |
                  readingStreams
                /       |       \
check if opened     pass *f()   close
                        ^
                        |
                    functionB()
*/

// when creating a std::ifstream object, passing file name as argument to its constructor
// it automatically attempts to open the file in the same location of the executable e.g. ./btc
void BitcoinExchange::readingStreams(const std::string &file, LineProcessor processor) {
  std::ifstream inputFile(file.c_str());

  if (!inputFile.is_open()) {
    std::cerr << "Error: could not open file — " << file << std::endl;
    return;
  }
  // skip the header line
  std::string header;
  if (!std::getline(inputFile, header)) {
    std::cerr << "Error: could not read header from file — " << file << std::endl;
    return;
  }
  // apply processing function in each line
  std::string line;
  while (std::getline(inputFile, line))
    processor(line, *this);
  inputFile.close();
}

void BitcoinExchange::loadDatabase(const std::string &line, BitcoinExchange &instance) {
  std::istringstream iss(line);
  std::string date;
  double price;
  if(std::getline(iss, date, ',') && iss >> price)
    instance.bitcoinPrices[date] = price;
}

// std::map is O(log n) each time [] operator is used
void BitcoinExchange::processInputFile(const std::string &line, BitcoinExchange &instance) {
  std::istringstream iss(line);
  std::map<std::string, double>::const_iterator it;
  std::string date;
  double price;
  try {
    if(std::getline(iss, date, '|') && iss >> price) {
    // finds the position of the last character that is not a whitespace character
    // substr(0, pos + 1) creates a substring from beginning to the position of the last non-whitespace char
    date = date.substr(0, date.find_last_not_of(" \t\n\r\f\v") + 1);
      it = instance.isValidDate(date);
      if (price < 0 || price > 1000)
        throw OutOfBoundsValue();
      std::cout << it->first << " => " << price << " = " << (it->second * price) << std::endl;
    } else {
      throw WrongInputFormat();
    }
  } catch(const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}

void BitcoinExchange::mapData(const std::string &file) {
  readingStreams("data.csv", BitcoinExchange::loadDatabase);
  readingStreams(file, BitcoinExchange::processInputFile);
}
