/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:35:29 by shinckel          #+#    #+#             */
/*   Updated: 2024/11/08 17:46:51 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(const Bureaucrat& clone) : _name(clone._name), _grade(clone._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& clone) {
  _grade = clone.getGrade();
  return *this;
}

const std::string Bureaucrat::getName(void) const {
  return _name;
}

int Bureaucrat::getGrade(void) const {
  return _grade;
}

void Bureaucrat::increment() {
  std::cout << "Increment" << std::endl;
}

void Bureaucrat::decrement() {
  std::cout << "Decrement" << std::endl;
}

// Overloaded operator<< function
std::ostream  &operator<<(std::ostream &out, const Bureaucrat &b) {
  Color::Modifier green(Color::FG_GREEN);
  Color::Modifier def(Color::FG_DEFAULT);

  out << green << "Bureaucrat: " << b.getName() << ", Grade: " << b.getGrade() << def;
  return out; 
}
