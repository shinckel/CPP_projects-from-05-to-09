/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:41:23 by shinckel          #+#    #+#             */
/*   Updated: 2024/12/19 18:11:47 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
  public:
    Intern();
    Intern(const Intern &clone);
    Intern &operator=(const Intern &clone);
    ~Intern();

    // someRandomIntern.makeForm("robotomy request", "Bender");
    AForm  *makeForm(std::string name, std::string target);

  private:
    struct FormType {
        std::string name;
        AForm *(Intern::*create)(std::string target);
    };

    static const FormType formTypes[3];

    AForm  *makePPF(std::string target);
    AForm  *makeRRF(std::string target);
    AForm  *makeSCF(std::string target);
};

#endif