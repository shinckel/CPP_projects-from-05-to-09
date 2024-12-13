/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:35:29 by shinckel          #+#    #+#             */
/*   Updated: 2024/11/26 21:25:50 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"

// encapsulation: exceptions are specific to this class
struct Bureaucrat::GradeTooHighException : public std::exception {
    Color::Modifier red;
    Color::Modifier def;

    GradeTooHighException() : red(Color::FG_RED), def(Color::FG_DEFAULT) {}

    const char* what() const throw() {
        std::ostringstream oss;
        oss << red << "Grade is too HIGH!" << def;
        std::string msg = oss.str();
        // Store the message in a static variable to ensure it persists
        static std::string static_msg = msg;
        return static_msg.c_str();
    }
};

struct  Bureaucrat::GradeTooLowException : public std::exception {
    Color::Modifier red;
    Color::Modifier def;

    GradeTooLowException() : red(Color::FG_RED), def(Color::FG_DEFAULT) {}

    const char* what() const throw() {
        std::ostringstream oss;
        oss << red << "Grade is too LOW!" << def;
        std::string msg = oss.str();
        // Store the message in a static variable to ensure it persists
        static std::string static_msg = msg;
        return static_msg.c_str();
    }
};

// struct  Bureaucrat::GradeTooLowException : public std::exception {
//   const char* what() const throw() {
//     return "Grade is too LOW!";
//   }
// };

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
  if (grade < 1)
    throw GradeTooHighException();
  if (grade > 150)
    throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(const Bureaucrat& clone) : _name(clone.getName()), _grade(clone.getGrade()) {
  // The grade checks, like the ones done in Bureaucrat constructor, might be unnecessary
  // as it is a copy of a valid Bureaucrat created before
}

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

// scope visibility: it is not tied to an instance of the class
// it is not an instance member, it is a nested type
// the compiler requires explicit qualification: Bureaucrat::GradeTooHighException()
void Bureaucrat::increment(void) {
  if (_grade == 1)
    throw Bureaucrat::GradeTooHighException();
  _grade--;
}

void Bureaucrat::decrement(void) {
  if (_grade == 150)
    throw Bureaucrat::GradeTooLowException();
  _grade++;
}

// Overloaded operator<< function
std::ostream  &operator<<(std::ostream &out, const Bureaucrat &b) {
  Color::Modifier green(Color::FG_GREEN);
  Color::Modifier def(Color::FG_DEFAULT);

  out << green << "Bureaucrat: " << b.getName() << ", Grade: " << b.getGrade() << def;
  return out; 
}

