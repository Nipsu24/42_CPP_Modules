/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:59:42 by mmeier            #+#    #+#             */
/*   Updated: 2025/01/31 15:25:26 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class PresidentialPardonForm : public AForm {
	private:
		std::string	mTarget;
	
	public:
		//Constructor
		PresidentialPardonForm(const std::string target);
		//Copy constructor
		PresidentialPardonForm(const PresidentialPardonForm& other);
		//Copy assignment operator
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		//Destructor
		~PresidentialPardonForm();
		
		//Methods:
};

#endif