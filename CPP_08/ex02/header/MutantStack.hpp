/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:21:28 by shinckel          #+#    #+#             */
/*   Updated: 2025/01/19 20:21:46 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// the goal is to create a MutantStack class that extends std::stack by making it iterable
// implement iterators for the MutantStack class so that you can traverse its elements using standard iterator operations
// the MutantStack should offer all the member functions of std::stack and additional iterator support
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <stack>
# include <vector>
# include <iostream>
# include <ostream>

template <class T>
class MutantStack : public std::stack<T> {
  public:
    MutantStack() : std::stack<T>() {}
	  MutantStack(const MutantStack &src) {*this = src;}
    MutantStack &operator=(const MutantStack &src) {
      this->c = src.c;
      return *this;
    }
	  ~MutantStack() {}
    // container_type: type alias within std::stack, accessing iterator type in underlying container
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    // "c" refers to the underlying container i.e. std::deque, that actually stores the elems of the stack
    // "c" is a protected member
     // cbegin(), cend(), crbegin(), and crend() are from C++11 and forbidden in this exercise
    iterator begin(void) { return this->c.begin(); }
    iterator end(void) { return this->c.end(); }
    reverse_iterator rbegin(void) { return this->c.rbegin(); }
    reverse_iterator rend(void) { return this->c.rend(); }
    const_iterator cbegin(void) const { return this->c.cbegin(); }
    const_iterator cend(void) const { return this->c.cend(); }
    const_reverse_iterator crbegin(void) const { return this->c.crbegin(); }
    const_reverse_iterator crend(void) const { return this->c.crend(); }
};

#endif