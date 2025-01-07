/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:29:40 by shinckel          #+#    #+#             */
/*   Updated: 2025/01/07 10:08:41 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>
# include <iterator>
# include <exception>

struct zeroOccurence : public std::exception {
  const char* what() const throw() {
    return "No occurence is found";
  }
};

// this function has to find the first occurrence
// of the second parameter in the first parameter (a container)
// if no occurence is found, throw exception
template <typename T>
typename T::iterator  easyfind(T& container, const int& i) {
  // std::cout << "Begin: " << container.begin() << std::endl;
  // std::cout << "End: " << container.end() << std::endl;

  typename T::iterator found = std::find(container.begin(), container.end(), i);
  if (found == container.end())
    throw zeroOccurence();
  return found;
}

#endif