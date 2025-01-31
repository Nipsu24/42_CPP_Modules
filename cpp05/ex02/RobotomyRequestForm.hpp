/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm copy.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:59:42 by mmeier            #+#    #+#             */
/*   Updated: 2025/01/31 15:09:04 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class RobotomyRequestForm : public AForm {
	private:
		std::string	mTarget;
	
	public:
		//Constructor
		RobotomyRequestForm(const std::string target);
		//Copy constructor
		RobotomyRequestForm(const RobotomyRequestForm& other);
		//Copy assignment operator
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		//Destructor
		~RobotomyRequestForm();
		
		//Methods:
};

#endif