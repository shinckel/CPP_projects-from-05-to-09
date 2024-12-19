/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:03:06 by shinckel          #+#    #+#             */
/*   Updated: 2024/12/18 00:53:30 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {
  _target = "default";
}

// Parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) {
  _target = target;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &clone) : AForm(clone) {
  _target = clone._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &clone) {
  _target = clone._target;
  return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void	PresidentialPardonForm::formExecution(void) const {
  Color::Modifier blue(Color::FG_L_BLUE);
  Color::Modifier def(Color::FG_DEFAULT);

  std::cout << blue << _target << " has been pardoned by Zaphod Beeblebrox" << def << std::endl;
}