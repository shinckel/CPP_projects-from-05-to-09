/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:15:54 by shinckel          #+#    #+#             */
/*   Updated: 2024/12/17 23:48:59 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Bureaucrat.hpp"

// the values _gradeToSign and _gradeToExecute follow the same rules as Bureau
// if it is to high or low and it is not in a try/catch, core dumped!
int main(void) {
	Bureaucrat b("Pesto", 5);
	Bureaucrat a = b; // copy constructor
	std::cout << a << std::endl;
	Bureaucrat c("Jamie", 32);
	a = c; // assignment operator
	std::cout << a << std::endl;
	Form Form1("Super important form", 45, 100);
  Form Form2("Top secret form", 1, 10);
	std::cout << Form1 << std::endl;
  std::cout << Form2 << std::endl;
	a.signForm(Form1);
	a.signForm(Form2);
	std::cout << Form1 << std::endl;
  std::cout << Form2 << std::endl;
	return 0;
}
