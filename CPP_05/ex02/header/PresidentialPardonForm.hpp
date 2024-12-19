/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:02:58 by shinckel          #+#    #+#             */
/*   Updated: 2024/12/18 00:54:19 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &clone);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &clone);
		~PresidentialPardonForm();
		void	formExecution() const; // override pure virtual function from AForm
};

#endif