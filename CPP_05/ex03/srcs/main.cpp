/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:02:31 by shinckel          #+#    #+#             */
/*   Updated: 2024/12/20 11:45:38 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Intern.hpp"

int main()
{
	Intern	Sady;
  Bureaucrat b("Big Boss", 1);

	AForm	*PP = Sady.makeForm("presidential pardon", "Nice Robot");
	AForm	*SC = Sady.makeForm("shrubbery creation", "Nice Robot");
	AForm	*RR = Sady.makeForm("robotomy request", "Nice Robot");
	AForm	*XX = Sady.makeForm("random form", "Fake");

	std::cout << *PP << std::endl; 
	std::cout << *SC << std::endl; 
	std::cout << *RR << std::endl;
	(void) XX; // it requires proper null checks before dereferencing pointers

  b.signForm(*RR);
  b.executeForm(*RR);
	b.signForm(*SC);
	b.executeForm(*SC);

	delete PP;
	delete SC;
	delete RR;
  return 0;
}