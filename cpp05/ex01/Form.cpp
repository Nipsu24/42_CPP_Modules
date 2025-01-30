/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:59:51 by mmeier            #+#    #+#             */
/*   Updated: 2025/01/30 15:11:15 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) 
	: mName(name), mIsSigned(false), mGradeToSign(gradeToSign), mGradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 )
		throw GradeTooHighException();
	if (gradeToSign > 150)
		throw GradeTooLowException();
	if (gradeToExecute < 1 )
		throw GradeTooHighException();
	if (gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: mName(other.mName), mIsSigned(other.mIsSigned),
	mGradeToSign(other.mGradeToSign), mGradeToExecute(other.mGradeToExecute) {}

Form& Form::operator=(const Form& other) {
	if (this == &other)
		return (*this);
	mIsSigned = other.mIsSigned;
	return (*this);
}

Form:: ~Form() {}

std::string	Form::getName() const { return (mName); }

int	Form::getGradeToSign() const { return (mGradeToSign); }

int	Form::getGradeToExecute() const { return (mGradeToExecute); }

bool	Form::getIsSigned() const { return (mIsSigned); }

/*Checks if the grade of a bureaucrat matches or is higher with the grade requrired
  to sign the form. Sets bool to true if the conditions are met, otherwise throws exception.*/
void	Form::beSigned(Bureaucrat& clerk) {
	if (clerk.getGrade() <= mGradeToSign)
		mIsSigned = true;
	else
		throw GradeTooLowException();
}

const char*	Form::GradeTooHighException::what() const noexcept {
	return ("the grade is too high!");
}

// Definition of GradeTooLowException's what() method
const char*	Form::GradeTooLowException::what() const noexcept {
	return ("the grade is too low!");
}

std::ostream& operator<<(std::ostream& os, const Form& paper) {
    os << paper.getName();
	os << ",";
	os << " with form signing grade ";
	os << paper.getGradeToSign();
	os << " and execution grade ";
	os << paper.getGradeToExecute();
	// os << ",";
    return (os);
}