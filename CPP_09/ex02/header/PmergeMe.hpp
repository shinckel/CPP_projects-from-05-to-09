/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:25:29 by shinckel          #+#    #+#             */
/*   Updated: 2025/02/27 19:01:04 by shinckel         ###   ########.fr       */
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

# define LOG(x) std::cout << x << std::endl;

// container choise: std::list and std::vector(array)
class PmergeMe {
  public:
    ~PmergeMe();
    static void mapData(char* argv[]);

  private:
    PmergeMe();
    PmergeMe(const PmergeMe &clone);
    PmergeMe &operator=(const PmergeMe &clone);
    void  sort();
    static bool  checkInput(const std::string& str);

    std::vector<int>  _vect;
    std::list<int>    _lst;
};

#endif