/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:59:42 by mmeier            #+#    #+#             */
/*   Updated: 2025/01/29 16:43:55 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form {
	private:
		const std::string	mName;
		bool				mIsSigned;
		const int			mGradeToSign;
		const int			mGradeToExecute;
	
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
		Form(const std::string name, const int gradeToSign, const int gradeToExecute);
		//Copy constructor
		Form(const Form& other);
		//Copy assignment operator
		Form& operator=(const Form& other);
		//Destructor
		~Form();
		
		//Methods:
		std::string		getName() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const ;
		bool			getIsSigned() const;
		void			beSigned(Bureaucrat& clerk);
};

std::ostream& operator<<(std::ostream& os, const Form& paper);

#endif