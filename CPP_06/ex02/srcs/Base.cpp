/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:00:46 by shinckel          #+#    #+#             */
/*   Updated: 2025/03/03 19:25:14 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/A.hpp"
#include "../header/B.hpp"
#include "../header/C.hpp"
#include "../header/Base.hpp"
#include "../header/Base.h"

Base::~Base(void) {
  std::cout << "Base destructor called" << std::endl;
}

Base* generate() {
  // seed random number from current time in seconds (time_t obj)
  // so it generates different sequences each time program runs
  srand(static_cast<unsigned int>(time(0)));
  int random = rand() % 3;
  switch (random) {
    case 0:
      return new A();
    case 1:
      return new B();
    case 2:
      return new C();
  }
  return NULL; // safeguard
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p)) {
    LOG("Dynamic cast reference: A");
  } else if (dynamic_cast<B*>(p)) {
    LOG("Dynamic cast reference: B");
  } else if (dynamic_cast<C*>(p)) {
    LOG("Dynamic cast reference: C");
  } else {
    LOG("Unknown type");
  }
}

void  identify(Base& p) {
  if (pointerDynamicCast<A>(p)) {
    LOG("Dynamic cast pointer: A");
  } else if (pointerDynamicCast<B>(p)) {
    LOG("Dynamic cast pointer: B");
  } else if (pointerDynamicCast<C>(p)) {
    LOG("Dynamic cast pointer: C");
  } else {
    LOG("Unknown type");
  }
}

// possible syntax, however not compatible to C++98
// T& t{dynamic_cast<T&>(p)};
template <typename T>
bool pointerDynamicCast(Base& p) {
  try {
    T& t = dynamic_cast<T&>(p);
    (void)t;
  } catch(std::exception& e) {
    return false;
  }
  return true;
}
