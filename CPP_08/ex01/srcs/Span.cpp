/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:59:39 by shinckel          #+#    #+#             */
/*   Updated: 2025/01/07 19:07:52 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Span.hpp"

// empty array
Span::Span(unsigned int size) : _maxSize(size) {
    _container.reserve(size); // Reserve space for the specified size
    _sorted = false;
}
// copy existent array
Span::Span(unsigned int size, const int arr[]) : _maxSize(size), _container(arr, arr + size), _sorted(false) {}

Span::~Span() { }

Span::Span(const Span &clone) : _maxSize(clone._maxSize), _container(clone._maxSize), _sorted(clone._sorted) {
  *this = clone;
}

Span &Span::operator=(const Span &clone) {
    if (this != &clone) {
        _maxSize = clone._maxSize;
        _container = clone._container;
        _sorted = clone._sorted;
    }
    return *this;
}

struct Span::SpanSizeTooBig : public std::exception {
  const char* what() const throw() {
    return "Span size too big, already reached max N elements";
  }
};

struct Span::SpanSizeTooSmall : public std::exception {
  const char* what() const throw() {
    return "Not enough elements to calculate span";
  }
};

void  Span::sortContainer(void) {
  std::sort(_container.begin(), _container.end());
  _sorted = true;
}

int Span::shortestSpan(void) {
  if (_container.size() < 2)
    throw SpanSizeTooSmall();
  if (!_sorted)
    sortContainer();
  int shortest = std::numeric_limits<int>::max();
  // std::vector<int>::size() returns a value of type std::vector<int>::size_type
  // use size_t or unsigned int for i
  for (size_t i = 1; i < _container.size(); ++i) {
    int span = _container[i] - _container[i - 1]; 
    if (span < shortest)
      shortest = span;
  }
  return shortest;
}

int Span::longestSpan(void) {
  if (_container.size() < 2)
    throw SpanSizeTooSmall();
  if (!_sorted)
    sortContainer();
  return *(_container.end() - 1) - *(_container.begin());
}

void Span::addNumber(int n) {
  if(_container.size() == _maxSize)
    throw SpanSizeTooBig();
  _container.push_back(n);
  _sorted = false;
}

void Span::addPlethoraNumbers(void) {
    srand(static_cast<int>(time(0))); // seed the random number generator
    while (_container.size() < _maxSize) {
        int random_number = rand() % 1000;
        addNumber(random_number);
    }
}

void Span::print(std::ostream &os) const {
    os << "[";
    for (std::vector<int>::size_type i = 0; i < _container.size(); ++i) {
        os << _container[i];
        if (i != _container.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
}

std::ostream &operator<<(std::ostream &os, const Span &span) {
    span.print(os);
    return os;
}
