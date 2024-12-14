/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:41:16 by shinckel          #+#    #+#             */
/*   Updated: 2024/12/14 02:04:51 by shinckel         ###   ########.fr       */
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
    int   _gradeToSign;
    int   _gradeToExecute;
};

std::ostream  &operator<<(std::ostream &out, const Form &n);

#endif