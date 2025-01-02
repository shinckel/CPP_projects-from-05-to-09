/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:34:50 by shinckel          #+#    #+#             */
/*   Updated: 2025/01/02 16:05:31 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

// swaps the values of two given arguments. Does not return anything
template <class T>
void  swap(T& a, T& b) {
  T tmp;

  tmp = a;
  a = b;
  b = tmp;
}

// compares the two values passed in its arguments and returns the smallest
// if the two of them are equal, then it returns the second one
template <class T>
T min(T a, T b) {
  return a < b ? a : b;
}

// compares the two values passed in its arguments and returns the greatest
// if the two of them are equal, then it returns the second one
template <class T>
T max(T a, T b) {
  return a > b ? a : b;
}

#endif