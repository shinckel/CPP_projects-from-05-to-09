/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:36:35 by shinckel          #+#    #+#             */
/*   Updated: 2024/12/17 17:37:54 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <ostream>
# include <exception>
# include <string>
# include <sstream> // concatenate strings
# include "Colors.hpp"
# include "AForm.hpp"

# define DEFAULT_NAME "Pesto"
# define DEFAULT_GRADE 50

// forward declaration, useful when there is a reference or pointer to the class
class AForm;

class Bureaucrat {
	public:
    // Orthodox Canonical Form
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& clone);
    Bureaucrat& operator=(const Bureaucrat& clone);

    // const at the end of the member function - it doesn't modify object
    // moreover, returned string can't be modified (getName)
		const   std::string getName() const;
    int     getGrade() const;
    void    increment();
    void    decrement();
    void    signForm(AForm &form); // takes a reference to an obj of the Form class
    void    executeForm(AForm const & form);
    struct  GradeTooHighException;
    struct  GradeTooLowException;

	private:
		const std::string _name;
    int   _grade;
};

std::ostream  &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
