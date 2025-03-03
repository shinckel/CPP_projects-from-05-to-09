/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:25:29 by shinckel          #+#    #+#             */
/*   Updated: 2025/03/03 15:47:23 by shinckel         ###   ########.fr       */
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
    // void printPairs() const;

  private:
    PmergeMe();
    PmergeMe(const PmergeMe &clone);
    PmergeMe &operator=(const PmergeMe &clone);

    void        fordJohnsonSort(PmergeMe &instance);
    void        mergeInsertVect(PmergeMe &instance);
    void        mergeInsertList(PmergeMe &instance);
    static bool checkInput(const std::string& str);
    struct      InvalidInput;

    std::vector<int>                  _v;
    std::vector<int>                  _sortedV;
    std::vector<std::pair<int, int> > _pairsV;
    std::list<int>                    _l;
    std::list<int>                    _sortedL;
    std::list<std::pair<int, int> >   _pairsL;    
};

#endif