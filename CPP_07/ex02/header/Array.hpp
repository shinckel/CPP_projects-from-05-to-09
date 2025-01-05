/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:02:53 by shinckel          #+#    #+#             */
/*   Updated: 2025/01/05 19:58:56 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

# define MAX_VAL 750

# include <iostream>
# include <stdlib.h>


template <class T>
class Array {
  public:
    // Array() {
    //   array = new T[0];
    //   _size = 0;
    // }
    Array() : array(NULL), _size(0) {};

    Array(unsigned int n) {
      array = new T[n];
      _size = n;
    }

    // changing cloned obj shouldn't affect original
    Array(const Array& clone) {
      array = new T[clone._size]; // allocating memory for the new array...
      // otherwise, both would point to the same data
      *this = clone; // copy contents of clone to the new array
    }

    // (operator=) cannot simply use *this = clone to perform a deep copy 
    // because this would create an infinite recursion
    Array& operator=(const Array& clone) {
      delete[] array;
      _size = clone._size;
      array = new T[_size];
      for(unsigned int i = 0; i < _size; i++)
        array[i] = clone.array[i];
      return *this;
    }

    ~Array() {
      delete[] array;
    }

    unsigned int size() {
      return _size;
    }

    struct OutOfBounds : public std::exception {
      const char* what() const throw() {
        return "Index out of bounds";
      }
    };

    T& operator[](unsigned int i) {
      if (i >= _size) {
        throw Array::OutOfBounds();
      }
      return array[i];
    }

  private:
    unsigned int _size;
    T* array;
};

#endif