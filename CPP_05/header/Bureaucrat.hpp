/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:36:35 by shinckel          #+#    #+#             */
/*   Updated: 2024/11/08 17:44:51 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <ostream>
# include <string>
# include "Colors.hpp"

class Bureaucrat {
	public:
    // Orthodox Canonical Form
    Bureaucrat(std::string name, int grade);
		~Bureaucrat();
    Bureaucrat(const Bureaucrat& clone);
    Bureaucrat& operator=(const Bureaucrat& clone);

    // const at the end of the member function - it doesn't modify object
    // moreover, returned string can't be modified (getName)
		const std::string getName() const;
    int     getGrade() const;

    void    increment();
    void    decrement();
    struct  GradeTooHighException;
    struct  GradeTooLowException;

	private:
		const std::string _name;
    int   _grade;
};

std::ostream  &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
