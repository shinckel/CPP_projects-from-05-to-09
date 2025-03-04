/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:25:29 by shinckel          #+#    #+#             */
/*   Updated: 2025/03/04 18:44:50 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <limits.h>
# include <string>
# include <list>
# include <vector>
# include <algorithm>
# include <time.h>
# include <sstream>

// LOG("Invalid input: " + std::string(*argv));
# define LOG(x) std::cout << x << std::endl;

// container choice: std::list and std::vector(array)
class PmergeMe {
  public:
    ~PmergeMe();
    static void mapData(char* argv[]);

  private:
    PmergeMe();
    PmergeMe(const PmergeMe &clone);
    PmergeMe &operator=(const PmergeMe &clone);

    static void fordJohnsonSort(PmergeMe &instance);
    static void mergeInsertVect(PmergeMe &instance);
    static void mergeInsertList(PmergeMe &instance);
    static bool checkInput(const std::string& str);
    struct      InvalidInput;

    std::vector<int>                  _vec;
    std::vector<int>                  _sortedVec;
    std::vector<std::pair<int, int> > _pairsVec;
    std::list<int>                    _lst;
    std::list<int>                    _sortedLst;
    std::list<std::pair<int, int> >   _pairsLst;

    template <typename T>
    static bool checkIfSorted(const T& sequence) {
        for (typename T::const_iterator it = sequence.begin(); it != sequence.end(); ++it) {
            typename T::const_iterator next = it;
            ++next;
            if (next != sequence.end() && *it > *next)
              return false;
        }
        return true;
    }
};

#endif