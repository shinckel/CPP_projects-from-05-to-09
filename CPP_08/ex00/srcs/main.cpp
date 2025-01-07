/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:32:00 by shinckel          #+#    #+#             */
/*   Updated: 2025/01/07 10:46:28 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/easyfind.hpp"

// VECTOR EXAMPLE
// int main(void) {
//   int arr[] = {1, 2, 3, 4, 5};
//   // std::vector<int> vec = {1, 2, 3, 4, 5}; not supported in C++98
//   std::vector<int> vec(5);
//   std::copy(arr, arr + 5, vec.begin());
//   vec.push_back(6);
//   std::cout << "Vector begin: " << *(vec.begin()) << std::endl;
//   // the end() iterator points to one past the last element of the vector
//   // reminder: this is contiguous memory, I can use arithmetic operation 
//   std::cout << "Vector end: " << *(vec.end() - 1) << std::endl;
//   try {
//     std::vector<int>::iterator it = easyfind(vec, 3);
//     std::cout << "Found occurence: " << *it << std::endl;
//     while(*it)
//       std::cout << "Parsing vector from iterator: " << *it++ << std::endl;
//     std::cout << "———————————————————————" << std::endl;
//     std::vector<int>::iterator it2 = easyfind(vec, 10);
//     std::cout << "Iterator: " << *it2 << std::endl;
//   } catch (std::exception &e) {
//     std::cout << e.what() << std::endl;
//   }
//   return 0;
// }

// LIST EXAMPLE
int main(void) {
  int arr[] = {7, 8, 9, 10, 11};
  std::list<int> lst;
  lst.insert(lst.end(), arr, arr + 5);
  lst.push_back(12);

  std::cout << "List begin: " << *(lst.begin()) << std::endl;
  // not contiguous memory, iterate the linked list for finding last node
  std::list<int>::iterator last_it = lst.end();
  --last_it;
  std::cout << "List end: " << *last_it << std::endl;
  try {
    std::list<int>::iterator it = easyfind(lst, 9);
    std::cout << "Found occurence: " << *it << std::endl;
    // doubly linked list, while(*it) will iterate forever
    while(it != lst.end())
      std::cout << "Parsing list from iterator: " << *it++ << std::endl;
    std::cout << "———————————————————————" << std::endl;
    std::list<int>::iterator it2 = easyfind(lst, 25);
    std::cout << "Iterator: " << *it2 << std::endl;
  } catch(std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
