/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:02:31 by shinckel          #+#    #+#             */
/*   Updated: 2024/12/19 18:16:21 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"

// now that AForm is abstract, its impossible to create a direct instance of it
// default values will be established throught concrete class
int main(void) {
  Bureaucrat b("Harry Potter", 1);
  // Association between abstract class and concrete class
  AForm *f1 = new PresidentialPardonForm("Pardon Form");
  PresidentialPardonForm p("Another Pardon Form");
  AForm &f2 = p;
  RobotomyRequestForm r("Nice Robot");
  AForm &f3 = r;
  ShrubberyCreationForm s("Shrubbery Tree");
  AForm &f4 = s;

  b.signForm(*f1);
  b.executeForm(*f1);
  b.signForm(f2);
  b.executeForm(f2);
  b.signForm(f3);
  b.executeForm(f3);
  b.signForm(f4);
  b.executeForm(f4);

  delete f1;
  return 0;
}
