/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:04:52 by shinckel          #+#    #+#             */
/*   Updated: 2025/02/27 10:07:16 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/RPN.hpp"

RPN::RPN() {};
RPN::~RPN() {};
RPN &RPN::operator=(const RPN &clone) { *this = clone; return *this; }
RPN::RPN(const RPN &clone) { *this = clone; }

void RPN::mapData(const std::string &exp) {
  std::istringstream iss(exp);
  std::string token;

  while (iss >> token) {
    if (std::isdigit(token[0])) {
      std::istringstream tokenStream(token);
      int num;
      tokenStream >> num;
      if (num >= 10) {
        throw "Numbers should be smaller than 10";
      }
      s.push(num);
    } else if (token == "+" || token == "-" || token == "*" || token == "/") {
      if (s.size() < 2) {
        throw "Invalid expression";
      }
      int b = s.top(); s.pop();
      int a = s.top(); s.pop();
      if (token == "+") s.push(a + b);
      else if (token == "-") s.push(a - b);
      else if (token == "*") s.push(a * b);
      else if (token == "/") {
        if (b == 0) throw "Division by zero";
        s.push(a / b);
      }
    } else {
      throw "Invalid token";
    }
  }

  if (s.size() != 1) {
    throw "Invalid expression";
  }

  LOG("Result: " << s.top());
}
