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

// this program should also handle const data types
// in the evaluation sheet there is a testing program using const
template <class T>
void iter(const T* arr, unsigned int size, void (*f)(const T&)) {
  for (unsigned int i = 0; i < size; i++) {
    f(arr[i]);
  }
}

// Overload for arrays of pointers to Base
template <class T>
void iter(T** arr, unsigned int size, void (*f)(T&)) {
  for (unsigned int i = 0; i < size; i++) {
    f(*arr[i]);
  }
}

template <class T>
void iter(T* const* arr, unsigned int size, void (*f)(const T&)) {
  for (unsigned int i = 0; i < size; i++) {
    f(*arr[i]);
  }
}

#endif
