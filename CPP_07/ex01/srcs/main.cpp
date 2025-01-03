/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:54:06 by shinckel          #+#    #+#             */
/*   Updated: 2025/01/03 12:52:58 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/iter.hpp"

// Base class
class Base {
  public:
    virtual ~Base() {}
    virtual void print() const = 0; // Pure virtual function
};

// Derived class A
class A : public Base {
  public:
    void print() const {
        std::cout << "A" << std::endl;
    }
};

// Derived class B
class B : public Base {
  public:
    void print() const {
        std::cout << "B" << std::endl;
    }
};

// Derived class C
class C : public Base {
  public:
    void print() const {
        std::cout << "C" << std::endl;
    }
};

template <class T>
void print(T& content) {
  std::cout << content << std::endl;
}

template <>
void print<Base>(Base& content) {
  content.print();
}

int main(void) {
  // Arrays are homogeneous, all elements same type
  int arrNum[] = {1, 2, 3, 4, 5};
  unsigned int sizeNum = sizeof(arrNum) / sizeof(arrNum[0]);

  std::string arrStr[] = {"banana", "apple", "coconut", "avocado"};
  unsigned int sizeStr = sizeof(arrStr) / sizeof(arrStr[0]);

  // Using polymorphism with pointers to a base class
  // Store pointers to different derived class objects in the same array
  Base* arrABC[] = {new A(), new B(), new C()};
  unsigned int sizeABC = sizeof(arrABC) / sizeof(arrABC[0]);

  std::cout << "Array of integers:" << std::endl;
  iter(arrNum, sizeNum, print<int>);

  std::cout << "Array of strings:" << std::endl;
  iter(arrStr, sizeStr, print<std::string>);

  std::cout << "Array of ABC objects:" << std::endl;
  iter(arrABC, sizeABC, print<Base>);

  // Clean up dynamically allocated memory
  for (unsigned int i = 0; i < sizeABC; i++) {
      delete arrABC[i];
  }

  return 0;
}
