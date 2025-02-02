/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:59:42 by mmeier            #+#    #+#             */
/*   Updated: 2025/01/31 17:57:34 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
	private:
		std::string	mTarget;
	
	public:
		//Constructor
		ShrubberyCreationForm(const std::string target);
		//Copy constructor
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		//Copy assignment operator
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		//Destructor
		~ShrubberyCreationForm();
		
		//Methods:
		void		drawTrees(const std::string target) const;
		std::string	drawSingleTree() const;
		void		execute(Bureaucrat const& executor) const;
		void		performShrubbery() const;
};

#endif