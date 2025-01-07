/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:00:35 by shinckel          #+#    #+#             */
/*   Updated: 2025/01/07 19:08:20 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>
# include <iterator>
# include <exception>
# include <limits>

class Span {
  public:
    Span(unsigned int size);
    Span(unsigned int size, const int arr[]);
    ~Span();
    Span(const Span &clone);
    Span &operator=(const Span &clone);

    // distance between all numbers stored e.g.: {6, 3, 17, 9, 11}
    // sort elements and compare adjacents, shortest: 9 - 11 = 2
    // sort elements and find min/max: longest: 17 - 3 = 14
    int     shortestSpan(void);
    int     longestSpan(void);
    void    addNumber(int n);
    void    addPlethoraNumbers(void);
    void    sortContainer(void);
    void    print(std::ostream &os) const;
    struct  SpanSizeTooBig; // attempt to store elements if there are already n
    struct  SpanSizeTooSmall; // there are no enought elements to calculate span

  private:
    unsigned int      _maxSize;
    std::vector<int>  _container;
    bool              _sorted;
};

std::ostream &operator<<(std::ostream &os, const Span &span);

#endif
