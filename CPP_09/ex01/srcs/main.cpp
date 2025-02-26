/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:04:56 by shinckel          #+#    #+#             */
/*   Updated: 2025/02/26 22:44:13 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/RPN.hpp"

// the program must take an inverted Polish mathematical expression as an argument
// handle operations with these tokens + - / *
// don't need to manage brackets or decimal numbers
// operands shouldn't be bigger than 10
int main(int argc, char* argv[]) {
  if (argc != 2) {
      std::cerr << "Usage: " << argv[0] << " '8 9 * 9 - 9 - 9 - 4 - 1 +'" << std::endl;
      return 1;
  }

  RPN r;
  try {
    r.mapData(argv[1]);
  } catch (const char *e) {
    std::cout << e << std::endl;
  }
  return 0;
}