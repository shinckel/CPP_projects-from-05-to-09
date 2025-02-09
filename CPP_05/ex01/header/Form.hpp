/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:41:16 by shinckel          #+#    #+#             */
/*   Updated: 2025/02/09 18:02:12 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
  public:
    // Orthodox Canonical Form
    Form(std::string name, int sign, int execute);
		~Form();
    Form(const Form& clone);
    Form& operator=(const Form& clone);

    const std::string getName() const;
    bool  getSigned() const;
    int   getGradeToSign() const;
    int   getGradeToExecute() const;
    void    beSigned(const Bureaucrat &b);
    struct  GradeTooHighException;
    struct  GradeTooLowException;

  private:
    const std::string _name;
    bool  _signed;
    const int   _gradeToSign;
    const int   _gradeToExecute;
};

std::ostream  &operator<<(std::ostream &out, const Form &n);

#endif