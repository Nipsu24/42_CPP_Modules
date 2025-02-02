/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:01:12 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/02 12:55:26 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include <iostream>
#include <stdexcept>

class Intern {
	private:
	
	public:
		class FormDoesNotExistException : public std::exception {
			public:
				const char* what() const noexcept override;
			};
		//Constructor
		Intern();
		//Copy constructor
		Intern(const Intern& other);
		//Copy assignment operator
		Intern& operator=(const Intern& other);
		//Destructor
		~Intern();
		
		//Methods:
		AForm*			makeForm(const std::string& formName, const std::string& target) const;
};

#endif