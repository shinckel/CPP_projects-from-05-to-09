/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:25:34 by shinckel          #+#    #+#             */
/*   Updated: 2025/02/27 19:13:17 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PmergeMe.hpp"

PmergeMe::PmergeMe() {};
PmergeMe::~PmergeMe() {};
PmergeMe &PmergeMe::operator=(const PmergeMe &clone) { *this = clone; return *this; }
PmergeMe::PmergeMe(const PmergeMe &clone) { *this = clone; }

void printVector(const std::vector<int>& vec) {
  LOG("Vector");
  for (size_t i = 0; i < vec.size(); ++i) {
      std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
}

void printList(const std::list<int>& lst) {
  LOG("List");
  for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
      std::cout << *it << " ";
  }
  std::cout << std::endl;
}

bool PmergeMe::checkInput(const std::string& str) {
  return (str.find_first_not_of("0123456789+") != std::string::npos ||
          str.find('+') != str.find_last_of('+') ||
          strtol(str.c_str(), NULL, 10) > INT_MAX ||
          strtol(str.c_str(), NULL, 10) < 1);
}

void PmergeMe::mapData(char* argv[]) {
  PmergeMe instance;
  // parse input

  // start clock
  // merge insert vector
  // stop clock and calc

  // start clock
  // merge insert list
  // stop clock and calc

  // render both sorted sequence and time

  // LOG("Invalid input: " + std::string(*argv));
  while(*argv) {
    if (PmergeMe::checkInput(*argv))
      exit(2);
    instance._vect.push_back(atoi(*argv));
    instance._lst.push_back(atoi(*argv));
    argv++;
  }
  printList(instance._lst);
  printVector(instance._vect);
}
