/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:24:53 by shinckel          #+#    #+#             */
/*   Updated: 2025/03/03 19:21:44 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

# define LOG(x) std::cout << x << std::endl;

// dynamic casting, and type identification in C++
// without using the typeinfo header or typeid operator
class Base {
  public:
    virtual ~Base();
};

#endif