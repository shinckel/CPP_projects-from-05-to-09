/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:25:29 by shinckel          #+#    #+#             */
/*   Updated: 2024/12/17 18:25:37 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/RobotomyRequestForm.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
  _target = "default";
}

// Parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) {
  _target = target;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &clone) : AForm(clone) {
  _target = clone._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &clone) {
  _target = clone._target;
  return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

// successfully 50% of the time. Otherwise, informs that the robotomy failed.
void	RobotomyRequestForm::formExecution(void) const {
  Color::Modifier blue(Color::FG_BLUE);
  Color::Modifier def(Color::FG_DEFAULT);

  std::cout << blue << "** DRILLING NOISES **" << def << std::endl;
  rand() % 2 ?
    std::cout << blue << _target << "has been robotomized successfully." << def << std::endl :
    std::cout << blue << "Robotomy failed for " << _target << def << std::endl;
}