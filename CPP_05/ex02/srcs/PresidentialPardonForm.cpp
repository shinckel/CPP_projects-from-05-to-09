/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:03:06 by shinckel          #+#    #+#             */
/*   Updated: 2025/02/09 17:05:25 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {
  _target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) {
  _target = target;
}

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