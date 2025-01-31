/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:59:42 by mmeier            #+#    #+#             */
/*   Updated: 2025/01/31 16:04:21 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm {
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
		AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
		//Copy constructor
		AForm(const AForm& other);
		//Copy assignment operator
		AForm& operator=(const AForm& other);
		//Destructor
		virtual ~AForm();
		
		//Methods:
		std::string		getName() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const ;
		bool			getIsSigned() const;
		void			beSigned(Bureaucrat& clerk);
		void			execute(Bureaucrat const& executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& paper);

#endif