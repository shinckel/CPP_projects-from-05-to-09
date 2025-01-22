/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:21:32 by shinckel          #+#    #+#             */
/*   Updated: 2025/01/19 20:25:23 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/MutantStack.hpp"

// code provided by 42 school in the subject
// in this example, push() pop() top() size() are built-in standard std::stack functions
// begin() end() are added to the MutantStack class to provide iterator support
// int main(void) {
//   MutantStack<int> mstack;

//   mstack.push(5);
//   mstack.push(17);
//   std::cout << mstack.top() << std::endl;
//   mstack.pop();
//   std::cout << mstack.size() << std::endl;
//   mstack.push(3);
//   mstack.push(5);
//   mstack.push(737);
//   //[...]
//   mstack.push(0);
//   MutantStack<int>::iterator it = mstack.begin();
//   MutantStack<int>::iterator ite = mstack.end();
//   ++it;
//   --it;
//   while (it != ite) {
//     std::cout << *it << std::endl;
//     ++it;
//   }
//   std::stack<int> s(mstack);
//   return 0;
// }

int main(void) {
  // only in cpp11
  // std::deque<int> d = {6, 3, 17, 9, 11};
  std::deque<int> d;
  d.push_back(10);
  d.push_back(20);
  d.push_back(30);
  d.push_front(5);
  d.push_front(0);

  std::deque<int>::iterator it = d.begin();
  ++it;
  d.insert(it, 2);
  for(it = d.begin(); it != d.end(); ++it)
    std::cout << *it << " ";
  std::cout << "\n————————————————————————————————" << std::endl;

  // std::stack has no push_back and front
  // it only provides push, top and pop for modifying the stack
  MutantStack<int> m;
  m.push(10);
  m.push(20);
  m.push(30);
  m.push(5);
  m.push(2);
  m.push(0);

  // render from bottom to the top, accessing elems in the order they are stored
  // 100 — 200 — 300 — 50 — 10
  for (MutantStack<int>::iterator it = m.begin(); it != m.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  std::cout << "Top element: " << m.top() << std::endl;
  m.pop();
  std::cout << "Top element after pop: " << m.top() << std::endl;

  for (MutantStack<int>::reverse_iterator it2 = m.rbegin(); it2 != m.rend(); ++it2)
    std::cout << *it2 << " ";
  std::cout << std::endl;
  return 0;
}