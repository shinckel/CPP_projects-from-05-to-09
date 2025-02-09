/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:01:42 by shinckel          #+#    #+#             */
/*   Updated: 2025/02/09 17:06:19 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {
  _target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) {
  _target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &clone) : AForm(clone) {
  _target = clone._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &clone) {
  _target = clone._target;
  return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

// create a file in the working directory, and writes ASCII trees inside it
void	ShrubberyCreationForm::formExecution(void) const {
  Color::Modifier pur(Color::FG_PURPLE);
  Color::Modifier red(Color::FG_RED);
  Color::Modifier def(Color::FG_DEFAULT);

  std::ofstream file;
  // method expects a C-style string (const char*) as first argument
  file.open((_target + "_shrubbery").c_str(), std::ios::out);
  if (!file) { // or file.fail()
    std::cout << red << "Error opening infile!" << std::endl;
    return;
  }
  file << "    oxoxoo    ooxoo\n  ooxoxo oo  oxoxooo\n oooo xxoxoo ooo ooox\n oxo o oxoxo  xoxxoxo\n  oxo xooxoooo o ooo\n    ooo\\oo\\  /o/o\n        \\  \\/ /\n         |   /\n         |  |\n         | D|\n         |  |\n         |  |\n  ______/____\\____\n";
	file.close();
}

