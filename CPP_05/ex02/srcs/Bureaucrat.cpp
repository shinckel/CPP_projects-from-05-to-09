/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:35:29 by shinckel          #+#    #+#             */
/*   Updated: 2024/12/18 00:45:30 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"

struct Bureaucrat::GradeTooHighException : public std::exception {
    Color::Modifier red;
    Color::Modifier def;

    GradeTooHighException() : red(Color::FG_RED), def(Color::FG_DEFAULT) {}

    const char* what() const throw() {
        std::ostringstream oss;
        oss << red << "Grade is too HIGH!" << def;
        static std::string static_msg = oss.str();
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
        static std::string static_msg = oss.str();
        return static_msg.c_str();
    }
};

Bureaucrat::Bureaucrat() : _name(DEFAULT_NAME), _grade(DEFAULT_GRADE) {
  if (_grade < 1)
    throw GradeTooHighException();
  if (_grade > 150)
    throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
  if (grade < 1)
    throw GradeTooHighException();
  if (grade > 150)
    throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(const Bureaucrat& clone) : _name(clone.getName()), _grade(clone.getGrade()) {}

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

std::ostream  &operator<<(std::ostream &out, const Bureaucrat &b) {
  Color::Modifier green(Color::FG_GREEN);
  Color::Modifier def(Color::FG_DEFAULT);

  out << green << "Bureaucrat: " << b.getName() << ", Grade: " << b.getGrade() << def;
  return out; 
}

// exception is established in Form::beSigned
void  Bureaucrat::signForm(AForm &form) {
  try {
    form.beSigned(*this);
    std::cout << _name + " signed " + form.getName() << std::endl;
  } catch(const std::exception& e) {
    std::cout << _name + " couln't sign " + form.getName() + " because " + e.what() << std::endl;
  }
}

void  Bureaucrat::executeForm(AForm const & form) {
  try {
    form.execute(*this);
    std::cout << _name + " executed " + form.getName() << std::endl;
  } catch(const std::exception& e) {
    std::cout << _name + " couldn't execute " + form.getName() + " because " + e.what() << std::endl; 
  }
}
