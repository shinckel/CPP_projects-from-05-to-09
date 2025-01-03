/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:24:53 by shinckel          #+#    #+#             */
/*   Updated: 2025/01/03 12:27:09 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

// practice polymorphism, dynamic casting, and type identification in C++
// without using the typeinfo header or typeid operator
class Base {
  public:
    virtual ~Base();
    virtual std::string getName(void) const =0;
    // randomly instanciates A, B or C, returns instance as a Base pointer
    static Base* generate(void);

     //both functions print the actual type of the object pointed to by p: "A", "B" or "C"
    static void identify(Base* p);
    // however, using a pointer inside the function below is forbidden
    static void identify(Base& p);

    template <typename T>
    static bool pointerDynamicCast(Base& p);
};

// possible syntax, however not compatible to C++98
// T& t{dynamic_cast<T&>(p)};
template <typename T>
bool Base::pointerDynamicCast(Base& p) {
  try {
    T& t = dynamic_cast<T&>(p);
    std::cout << "Dynamic cast pointer: "<< t.getName() << std::endl;
  } catch(std::exception& e) {
    // std::cerr << e.what() << std::endl;
    return false;
  }
  return true;
}

#endif