/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:25:34 by shinckel          #+#    #+#             */
/*   Updated: 2025/03/03 16:04:20 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PmergeMe.hpp"

PmergeMe::PmergeMe() {};
PmergeMe::~PmergeMe() {};
PmergeMe &PmergeMe::operator=(const PmergeMe &clone) { *this = clone; return *this; }
PmergeMe::PmergeMe(const PmergeMe &clone) { *this = clone; }

struct  PmergeMe::InvalidInput : public std::exception {
  const char* what() const throw() {
    return "\033[1;41m Invalid input! Please add a positive integer sequence \033[0m";
  }
};

// UTILS DEBUGGING
void printVector(const std::vector<int>& vec) {
  for (size_t i = 0; i < vec.size(); ++i) {
      std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
}

// UTILS DEBUGGING
void printPairs(std::vector<std::pair<int, int> >& vec) {
  for (std::vector<std::pair<int, int> >::const_iterator it = vec.begin(); it != vec.end(); ++it) {
      std::cout << "(" << it->first << ", " << it->second << ") ";
  }
  std::cout << std::endl;
}

// UTILS DEBUGGING
void printList(const std::list<int>& lst) {
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

// reserves space for the pairs that will be added to _pairsV
// so, vector does not need to reallocate memory as pairs are added, which can improve performance
void PmergeMe::mergeInsertVect(PmergeMe &i) {
  // check if already sorted

  std::pair<int, int> pair;
  std::vector<std::pair<int, int> > partitions;
  partitions.reserve(i._v.size() / 2 + i._v.size() % 2);

  for (size_t j = 0; j < i._v.size(); j += 2) {
    if (j + 1 < i._v.size()) { // if there is a pair
      pair = std::make_pair(std::min(i._v[j], i._v[j + 1]), std::max(i._v[j], i._v[j + 1]));
    } else { // if not, second elem remains uninitialized
      pair.first = i._v[j];
      pair.second = '\0';
    }
    partitions.push_back(pair);
  }
  // printPairs(partitions); // debugging  

  i._pairsV.reserve(partitions.size());
  for (size_t j = 0; j < partitions.size(); j++) {
    std::vector<std::pair<int, int> >::iterator it = lower_bound(i._pairsV.begin(), i._pairsV.end(), partitions[j]);
    i._pairsV.insert(it, partitions[j]);
  }

  for (size_t j = 0; j < i._pairsV.size(); j++) {
    i._sortedV.push_back(i._pairsV[j].first);
  }

  for (size_t j = 0; j < i._pairsV.size(); j++) {
    std::vector<int>::iterator it = lower_bound(i._sortedV.begin(), i._sortedV.end(), i._pairsV[j].second);
    if (i._pairsV[j].second)
      i._sortedV.insert(it, i._pairsV[j].second);
  }
  // printVector(i._sortedV); // debugging
}

void  PmergeMe::mergeInsertList(PmergeMe &i) {
  // check if already sorted

  std::pair<int, int> pair;
  std::list<std::pair<int, int> > partitions;

  for (size_t j = 0; j < i._v.size(); j += 2) {
    if (j + 1 < i._v.size()) { // if there is a pair
      pair = std::make_pair(std::min(i._v[j], i._v[j + 1]), std::max(i._v[j], i._v[j + 1]));
    } else { // if not, second elem remains uninitialized
      pair.first = i._v[j];
      pair.second = '\0';
    }
    partitions.push_back(pair);
  }
  // printPairs(partitions); // debugging  

  i._pairsV.reserve(partitions.size());
  for (size_t j = 0; j < partitions.size(); j++) {
    std::vector<std::pair<int, int> >::iterator it = lower_bound(i._pairsV.begin(), i._pairsV.end(), partitions[j]);
    i._pairsV.insert(it, partitions[j]);
  }

  for (size_t j = 0; j < i._pairsV.size(); j++) {
    i._sortedV.push_back(i._pairsV[j].first);
  }

  for (size_t j = 0; j < i._pairsV.size(); j++) {
    std::vector<int>::iterator it = lower_bound(i._sortedV.begin(), i._sortedV.end(), i._pairsV[j].second);
    if (i._pairsV[j].second)
      i._sortedV.insert(it, i._pairsV[j].second);
  }
}

// divide and conquer: the algorithm divides the input list into smaller sublists
// it recursively sorts the sublists using merge sort
// it then uses insertion sort to merge the sorted sublists into a single sorted list
void  PmergeMe::fordJohnsonSort(PmergeMe &i) {
  clock_t start = clock();
  mergeInsertVect(i);
  clock_t finishVector = clock() - start;

  start = clock();
  mergeInsertList(i);
  clock_t finishList = clock() - start;

  LOG("\033[1;43m VECTOR before: \033[0m");
  printVector(i._v);
  LOG("\033[1;43m VECTOR after: \033[0m");
  printVector(i._sortedV);
  std::cout << "\033[1;42m Time to process a range of " << i._v.size() << " elements with std::vector : " << \
		static_cast<float>(finishVector) / CLOCKS_PER_SEC * 1000 << " ms \033[0m" << std::endl;

  LOG("---------------------------------------------------------------------------")

  LOG("\033[1;43m LIST before: \033[0m");
  printVector(i._l);
  LOG("\033[1;43m LIST after: \033[0m");
  printVector(i._sortedL);
  std::cout << "\033[1;42m Time to process a range of " << i._l.size() << " elements with std::list : " << \
		static_cast<float>(finishList) / CLOCKS_PER_SEC * 1000 << " ms \033[0m" << std::endl;
}

void PmergeMe::mapData(char* argv[]) {
  PmergeMe instance;

  while(*argv) {
    try {
      if (PmergeMe::checkInput(*argv))
        throw InvalidInput();
      instance._v.push_back(atoi(*argv));
      instance._l.push_back(atoi(*argv));
      argv++;
    } catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
      return;
    }
  }
  // printList(instance._l); // debugging
  // printVector(instance._v); // debugging
  instance.fordJohnsonSort(instance);
}
