/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:02:31 by shinckel          #+#    #+#             */
/*   Updated: 2024/12/19 18:20:34 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Intern.hpp"

int main()
{
	Intern	Sady;
  Bureaucrat b("Big Boss", 1);

	AForm	*PP = Sady.makeForm("presidential pardon", "Pauleta");
	AForm	*SC = Sady.makeForm("shrubbery creation", "Pauleta");
	AForm	*RR = Sady.makeForm("robotomy request", "Pauleta");
	AForm	*XX = Sady.makeForm("ola", "Pauleta");

	(void) XX;
	std::cout << *PP << std::endl; 
	std::cout << *SC << std::endl; 
	std::cout << *RR << std::endl;

  b.signForm(*RR);
  b.executeForm(*RR);
  return 0;
}