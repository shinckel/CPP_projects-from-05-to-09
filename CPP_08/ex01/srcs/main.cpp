/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:53:41 by shinckel          #+#    #+#             */
/*   Updated: 2025/03/12 19:09:19 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Span.hpp"

int main(void) {
  int arr[] = {6, 3, 17, 9, 11};
  Span v((sizeof(arr) / sizeof(arr[0])), arr);
  std::cout << v << std::endl;
  std::cout << "Shortest from v: " << v.shortestSpan() << std::endl;
  std::cout << "Longest from v: " << v.longestSpan() << std::endl;

  Span v2(5);
  std::cout << "———————————————————————\n" << std::endl;
  std::cout << "Empty vector: " << v2 << std::endl;
  try {
    v2.addNumber(54);
    v2.addNumber(76);
    v2.addNumber(101);
    v2.addNumber(5);
    v2.addNumber(17);
    v2.sortContainer();
    std::cout << v2 << std::endl;
    std::cout << "Shortest from v2: " << v2.shortestSpan() << std::endl;
    std::cout << "Longest from v2: " << v2.longestSpan() << std::endl;
    v2.addNumber(300);
  } catch(std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  Span v3(10000);
  v3.addPlethoraNumbers();
  v3.sortContainer();
  std::cout << "———————————————————————\n" << std::endl;
  std::cout << v3 << std::endl;
  std::cout << "Shortest from v3: " << v3.shortestSpan() << std::endl;
  std::cout << "Longest from v3: " << v3.longestSpan() << std::endl;

  Span v4(1);
  v4.addNumber(1);
  try {
    v4.shortestSpan();
  } catch(std::exception& e) {
    std::cout << "———————————————————————\n" << std::endl;
    std::cout << e.what() << std::endl;
  }

  Span v5 = v2;
  std::cout << "———————————————————————\n" << std::endl;
  std::cout << "Copy constructor: " << v5 << std::endl;
  v5 = v;
  std::cout << "Assignment operator v5: " << v5 << std::endl;
  std::cout << "Source vector v2 doesn't change: " << v2 << std::endl;
  return 0;
}