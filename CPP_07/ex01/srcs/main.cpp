/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:54:06 by shinckel          #+#    #+#             */
/*   Updated: 2025/02/26 11:18:21 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/iter.hpp"

// base class
class Base {
  public:
    virtual ~Base() {}
    virtual void print() const = 0; // Pure virtual function
};

// derived class A
class A : public Base {
  public:
    void print() const {
        std::cout << "A" << std::endl;
    }
};

// derived class B
class B : public Base {
  public:
    void print() const {
        std::cout << "B" << std::endl;
    }
};

// derived class C
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

// printing const data types, otherwise it will raise errors
template <class T>
void print(const T& content) {
  std::cout << content << std::endl;
}

template <>
void print<Base>(Base& content) {
  content.print();
}

template <>
void print<const Base>(const Base& content) {
  content.print();
}

int main(void) {
  // arrays are homogeneous, all elements same type
  const int arrConstNum[] = {1, 2, 3, 4, 5};
  unsigned int sizeConstNum = sizeof(arrConstNum) / sizeof(arrConstNum[0]);

  const int arrNum[] = {6, 7, 8};
  unsigned int sizeNum = sizeof(arrNum) / sizeof(arrNum[0]);

  std::string arrStr[] = {"banana", "apple", "coconut", "avocado"};
  unsigned int sizeStr = sizeof(arrStr) / sizeof(arrStr[0]);

  // using polymorphism with pointers to a base class
  // store pointers to different derived class objects in the same array
  const Base* arrConstABC[] = {new C(), new B(), new A()};
  unsigned int sizeConstABC = sizeof(arrConstABC) / sizeof(arrConstABC[0]);

  Base* arrABC[] = {new A(), new B(), new C()};
  unsigned int sizeABC = sizeof(arrABC) / sizeof(arrABC[0]);

  std::cout << "Array of const integers:" << std::endl;
  iter(arrConstNum, sizeConstNum, print<const int>);

  std::cout << "Array of integers:" << std::endl;
  iter(arrNum, sizeNum, print<int>);

  std::cout << "Array of strings:" << std::endl;
  iter(arrStr, sizeStr, print<std::string>);

  std::cout << "Array of const ABC objects:" << std::endl;
  iter(arrConstABC, sizeConstABC, print<const Base>);

  std::cout << "Array of ABC objects:" << std::endl;
  iter(arrABC, sizeABC, print<Base>);

  // clean up dynamically allocated memory
  for (unsigned int i = 0; i < sizeABC; i++) {
    delete arrConstABC[i];
    delete arrABC[i];
  }

  return 0;
}
