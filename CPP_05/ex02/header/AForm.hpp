/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:01:11 by shinckel          #+#    #+#             */
/*   Updated: 2024/12/18 00:32:49 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Abstract class, thats why the usage of prefix A
// Why classes? Program organisation, fundamental concepts
// Mapping of concepts — a class is a type
// Re-use — Useful concepts isolated and represented clearly
#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
  public:
    // Orthodox Canonical Form
    AForm(std::string name, int sign, int execute);
		virtual ~AForm();
    AForm(const AForm& clone);
    AForm& operator=(const AForm& clone);

    const   std::string getName() const;
    bool    getSigned() const;
    int     getGradeToSign() const;
    int     getGradeToExecute() const;
    void    beSigned(const Bureaucrat &b);
    struct  GradeTooHighException;
    struct  GradeTooLowException;
    struct	NotSigned;
    void    execute(Bureaucrat const & executor) const;
	  virtual void formExecution() const = 0; // pure virtual function

protected:
    std::string _target; // used as base for all derived classes

  private:
    const std::string _name;
    bool  _signed;
    int   _gradeToSign;
    int   _gradeToExecute;
};

std::ostream  &operator<<(std::ostream &out, const AForm &n);

#endif