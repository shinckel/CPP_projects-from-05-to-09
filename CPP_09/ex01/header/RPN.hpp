/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:05:06 by shinckel          #+#    #+#             */
/*   Updated: 2025/02/26 22:39:30 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

# include <stack>
# include <vector>
# include <iostream>
# include <ostream>
# include <sstream>
# include <cstdlib> // atoi
# include <cctype> // isdigit

// container choise: std::stack, last thing in first thing out storage mechanism
class RPN {
  public:
    RPN();
    RPN(const RPN &clone);
    RPN &operator=(const RPN &clone);
    ~RPN();

    void mapData(const std::string &exp);

    private:
      std::stack<int> s;
};

#endif