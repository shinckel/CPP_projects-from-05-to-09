/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:56:00 by shinckel          #+#    #+#             */
/*   Updated: 2025/01/03 12:45:45 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

// 3 parameters: array address, array length and function that will be called in every element
// third parameter can be an instantiated function template
template <class T>
void iter(T* arr, unsigned int size, void (*f)(T&)) {
  for (unsigned int i = 0; i < size; i++)
    f(arr[i]);
}

// Overload for arrays of pointers to Base
template <class T>
void iter(T** arr, unsigned int size, void (*f)(T&)) {
    for (unsigned int i = 0; i < size; i++) {
        f(*arr[i]);
    }
}

#endif