/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:24:53 by shinckel          #+#    #+#             */
/*   Updated: 2025/02/11 18:41:19 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

// dynamic casting, and type identification in C++
// without using the typeinfo header or typeid operator
class Base {
  public:
    virtual ~Base();
};

// randomly instanciates A, B or C, returns instance as a Base pointer
Base* generate(void);
//both functions print the actual type of the object pointed to by p: "A", "B" or "C"
void  identify(Base* p);
// however, using a pointer inside the function below is forbidden
void  identify(Base& p);
void  printBase(std::string str);

template <typename T>
bool pointerDynamicCast(Base& p);

#endif