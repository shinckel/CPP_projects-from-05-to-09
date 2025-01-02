/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:00:46 by shinckel          #+#    #+#             */
/*   Updated: 2025/01/02 15:46:14 by shinckel         ###   ########.fr       */
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

void Base::identify(Base& p) {
  if (pointerDynamicCast<A>(p)) return;
  if (pointerDynamicCast<B>(p)) return;
  if (pointerDynamicCast<C>(p)) return;
}
