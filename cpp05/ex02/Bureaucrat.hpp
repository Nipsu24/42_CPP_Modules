/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:01:12 by mmeier            #+#    #+#             */
/*   Updated: 2025/01/31 18:02:19 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>
#include <stdexcept>

class AForm;

class Bureaucrat {
	private:
		const std::string	mName;
		int					mGrade;
	
	public:
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept override;
		};
		
		//Constructor
		Bureaucrat(const std::string name, int grade);
		//Copy constructor
		Bureaucrat(const Bureaucrat& other);
		//Copy assignment operator
		Bureaucrat& operator=(const Bureaucrat& other);
		//Destructor
		~Bureaucrat();
		
		//Methods:
		std::string		getName() const;
		int				getGrade() const;
		void			incrementGrade();
		void			decrementGrade();
		void			signForm(AForm& paper);
		void			executeForm(AForm const& form);
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& clerk);

#endif