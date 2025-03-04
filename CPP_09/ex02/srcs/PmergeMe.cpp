/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:25:34 by shinckel          #+#    #+#             */
/*   Updated: 2025/03/04 18:55:10 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PmergeMe.hpp"

PmergeMe::PmergeMe() {};
PmergeMe::~PmergeMe() {};
PmergeMe &PmergeMe::operator=(const PmergeMe &clone) { (void)clone; return *this; }
PmergeMe::PmergeMe(const PmergeMe &clone) { (void)clone; }

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

void printPairs(std::list<std::pair<int, int> >& vec) {
  for (std::list<std::pair<int, int> >::const_iterator it = vec.begin(); it != vec.end(); ++it) {
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

// reserves space for the pairs that will be added to _pairsVec
// so, vector does not need to reallocate memory as pairs are added, which can improve performance
void PmergeMe::mergeInsertVect(PmergeMe &i) {
  i._sortedVec.reserve(i._vec.size());
  if (checkIfSorted(i._vec)) {
    i._sortedVec = i._vec;
    return ;
  }

  std::pair<int, int> pair;
  std::vector<std::pair<int, int> > partitions;
  partitions.reserve(i._vec.size() / 2 + i._vec.size() % 2);

  for (size_t j = 0; j < i._vec.size(); j += 2) {
    if (j + 1 < i._vec.size()) { // if there is a pair
      pair = std::make_pair(std::min(i._vec[j], i._vec[j + 1]), std::max(i._vec[j], i._vec[j + 1]));
    } else { // if not, second elem remains uninitialized
      pair.first = i._vec[j];
      pair.second = '\0';
    }
    partitions.push_back(pair);
  }
  // printPairs(partitions); // debugging  

  i._pairsVec.reserve(partitions.size());
  for (size_t j = 0; j < partitions.size(); j++) {
    std::vector<std::pair<int, int> >::iterator it = lower_bound(i._pairsVec.begin(), i._pairsVec.end(), partitions[j]);
    i._pairsVec.insert(it, partitions[j]);
  }

  for (size_t j = 0; j < i._pairsVec.size(); j++) {
    i._sortedVec.push_back(i._pairsVec[j].first);
  }

  for (size_t j = 0; j < i._pairsVec.size(); j++) {
    std::vector<int>::iterator it = lower_bound(i._sortedVec.begin(), i._sortedVec.end(), i._pairsVec[j].second);
    if (i._pairsVec[j].second)
      i._sortedVec.insert(it, i._pairsVec[j].second);
  }
  // printVector(i._sortedVec); // debugging
}

void PmergeMe::mergeInsertList(PmergeMe &i) {
  if (checkIfSorted(i._lst)) {
    i._sortedLst = i._lst;
    return ;
  }

  std::pair<int, int> pair;
  std::list<std::pair<int, int> > partitions;
  for (std::list<int>::const_iterator it = i._lst.begin(); it != i._lst.end(); std::advance(it, 2)) {
      std::list<int>::const_iterator first = it;
      std::list<int>::const_iterator second = it;
      std::advance(second, 1);
      if (second == i._lst.end()) {
        pair.first = *first;
        pair.second = '\0';
        partitions.push_back(pair);
        break;
      } else {
        pair = std::make_pair(std::min(*first, *second), std::max(*first, *second));
      }
      partitions.push_back(pair);
  }

  // printPairs(partitions); // debugging
  
  for (std::list<std::pair<int, int> >::const_iterator it = partitions.begin(); it != partitions.end(); ++it) {
    i._pairsLst.insert(lower_bound(i._pairsLst.begin(), i._pairsLst.end(), *it), *it);
  }

  for (std::list<std::pair<int, int> >::const_iterator it = i._pairsLst.begin(); it != i._pairsLst.end(); ++it) {
    i._sortedLst.push_back(it->first);
  }

  for (std::list<std::pair<int, int> >::const_iterator it = i._pairsLst.begin(); it != i._pairsLst.end(); ++it) {
    if (it->second) {
      i._sortedLst.insert(lower_bound(i._sortedLst.begin(), i._sortedLst.end(), (*it).second), (*it).second);
    }
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
  printVector(i._vec);
  LOG("\033[1;43m VECTOR after: \033[0m");
  printVector(i._sortedVec);
  std::cout << "\033[1;42m Time to process a range of " << i._vec.size() << " elements with std::vector : " << \
		static_cast<float>(finishVector) / CLOCKS_PER_SEC * 1000 << " ms \033[0m" << std::endl;

  LOG("---------------------------------------------------------------------------")

  LOG("\033[1;43m LIST before: \033[0m");
  printList(i._lst);
  LOG("\033[1;43m LIST after: \033[0m");
  printList(i._sortedLst);
  std::cout << "\033[1;42m Time to process a range of " << i._lst.size() << " elements with std::list : " << \
		static_cast<float>(finishList) / CLOCKS_PER_SEC * 1000 << " ms \033[0m" << std::endl;
}

void PmergeMe::mapData(char* argv[]) {
  PmergeMe instance;

  while(*argv) {
    try {
      if (PmergeMe::checkInput(*argv))
        throw InvalidInput();
      instance._vec.push_back(atoi(*argv));
      instance._lst.push_back(atoi(*argv));
      argv++;
    } catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
      return;
    }
  }
  // printList(instance._lst); // debugging
  // printVector(instance._vec); // debugging
  fordJohnsonSort(instance);
}
