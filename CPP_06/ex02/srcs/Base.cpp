/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:00:46 by shinckel          #+#    #+#             */
/*   Updated: 2025/01/02 15:09:16 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/A.hpp"
#include "../header/B.hpp"
#include "../header/C.hpp"
#include "../header/Base.hpp"

Base::~Base(void) {
  std::cout << "Base destructor called" << std::endl;
}

Base* Base::generate() {
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

void Base::identify(Base* p) {
  if (dynamic_cast<A*>(p))
    std::cout << "Dynamic cast reference: A" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "Dynamic cast reference: B" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "Dynamic cast reference: C" << std::endl;
  else
    std::cout << "unknown type" << std::endl;
}

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

void Base::identify(Base& p) {
  if (pointerDynamicCast<A>(p)) return;
  if (pointerDynamicCast<B>(p)) return;
  if (pointerDynamicCast<C>(p)) return;
}
