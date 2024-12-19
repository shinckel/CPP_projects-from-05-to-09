/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:41:29 by shinckel          #+#    #+#             */
/*   Updated: 2024/12/19 18:24:40 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Intern.hpp"

const Intern::FormType Intern::formTypes[3] = {
    {"presidential pardon", &Intern::makePPF()},
    {"robotomy request", &Intern::makeRRF()},
    {"shrubbery creation", &Intern::makeSCF()}
};

Intern::Intern() {}

Intern::Intern(const Intern &clone) {
    *this = clone;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &clone) {
    (void)clone;
    return *this;
}

AForm *Intern::makePPF(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeRRF(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::makeSCF(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target) {
    for (int i = 0; i < 3; ++i) {
        if (formTypes[i].name == name) {
            return (this->*formTypes[i].create)(target);
        }
    }
    std::cerr << "Error: Form type '" << name << "' not recognized." << std::endl;
    return NULL;
}
