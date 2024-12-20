/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:02:41 by shinckel          #+#    #+#             */
/*   Updated: 2024/12/19 18:00:35 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <stdlib.h>
# include "AForm.hpp"

class RobotomyRequestForm: public AForm {
  public:
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &clone);
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &clone);
    ~RobotomyRequestForm();
    void  formExecution() const; // override pure virtual function from AForm
};

#endif
