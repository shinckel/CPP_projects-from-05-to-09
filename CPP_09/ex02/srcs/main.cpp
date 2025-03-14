/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:25:31 by shinckel          #+#    #+#             */
/*   Updated: 2025/03/03 10:14:02 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PmergeMe.hpp"

// ./PmergeMe 3 5 9 7 4
// it combines the principles of merge sort and insertion sort
int main(int argc, char* argv[]) {
  if (argc < 2) {
      std::cerr << "Usage: " << argv[0] << "3 5 9 7 4" << std::endl;
      return 1;
  }

  PmergeMe::mapData(argv + 1);
  return 0;
}