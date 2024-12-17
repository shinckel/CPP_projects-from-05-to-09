/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:01:22 by shinckel          #+#    #+#             */
/*   Updated: 2024/12/17 17:39:32 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/AForm.hpp"

struct AForm::GradeTooHighException : public std::exception {
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

struct  AForm::GradeTooLowException : public std::exception {
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
// at its construction, the form is not signed = 0
// same rules applied to bureaucrat grades are applied here
AForm::AForm(std::string name, int sign, int execute) : _name(name), _signed(0), _gradeToSign(sign), _gradeToExecute(execute) {
  if (_gradeToSign < 1 || _gradeToExecute < 1)
    throw GradeTooHighException();
  if (_gradeToSign > 150 || _gradeToExecute > 150)
    throw GradeTooLowException();
}

AForm::~AForm(void) {}

AForm::AForm(const AForm& clone) : _name(clone.getName()), _signed(clone.getSigned()), _gradeToSign(clone.getGradeToSign()), _gradeToExecute(clone.getGradeToExecute()) {}

AForm& AForm::operator=(const AForm& clone) {
  _signed = clone.getSigned();
  return (*this);
}

const std::string AForm::getName(void) const {
  return _name;
}

bool  AForm::getSigned(void) const {
  return _signed;
}

int  AForm::getGradeToSign(void) const {
  return _gradeToSign;
}

int  AForm::getGradeToExecute(void) const {
  return _gradeToExecute;
}

// overload of the insertion operator (<<) that prints all informations
std::ostream& operator<<(std::ostream& out, const AForm& form) {
  Color::Modifier red(Color::FG_RED);
  Color::Modifier def(Color::FG_DEFAULT);

  out << "Form " << form.getName() << " is ";
  out << red << (form.getSigned() ? "" : "not ") << def;
  out << "signed. Its sign grade is " << form.getGradeToSign() << " and its execution grade is " << form.getGradeToExecute();
  return out;
}

// it changes the form status to signed if the bureaucrats grade is high enough
void  AForm::beSigned(const Bureaucrat& b) {
  if(b.getGrade() >= _gradeToSign)
    throw Form::GradeTooLowException();
  _signed = 1;
}

void    execute(Bureaucrat const & executor) const {
  
}
