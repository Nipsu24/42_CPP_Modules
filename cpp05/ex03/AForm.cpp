/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:59:51 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/04 11:28:34 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) 
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

AForm::AForm(const AForm& other)
	: mName(other.mName), mIsSigned(other.mIsSigned),
	mGradeToSign(other.mGradeToSign), mGradeToExecute(other.mGradeToExecute) {}

AForm& AForm::operator=(const AForm& other) {
	if (this == &other)
		return (*this);
	mIsSigned = other.mIsSigned;
	return (*this);
}

AForm:: ~AForm() {}

std::string	AForm::getName() const { return (mName); }

int	AForm::getGradeToSign() const { return (mGradeToSign); }

int	AForm::getGradeToExecute() const { return (mGradeToExecute); }

bool	AForm::getIsSigned() const { return (mIsSigned); }

/*Checks if the grade of a bureaucrat matches or is higher with the grade requrired
  to sign the form. Sets bool to true if the conditions are met, otherwise throws exception.*/
void	AForm::beSigned(Bureaucrat& clerk) {
	if (clerk.getGrade() <= mGradeToSign)
		mIsSigned = true;
	else
		throw GradeTooLowException();
}

const char*	AForm::GradeTooHighException::what() const noexcept {
	return ("the grade is too high!");
}

// Definition of GradeTooLowException's what() method
const char*	AForm::GradeTooLowException::what() const noexcept {
	return ("the grade is too low!");
}

std::ostream& operator<<(std::ostream& os, const AForm& paper) {
    os << paper.getName();
	os << ",";
	os << " with form signing grade ";
	os << paper.getGradeToSign();
	os << " and execution grade ";
	os << paper.getGradeToExecute();
    return (os);
}

void AForm::checkExecutionRequirements(Bureaucrat const& executor) const {
	if (!mIsSigned)
		throw FormNotSignedException();
	if (mGradeToExecute < executor.getGrade())
		throw GradeTooLowException();
}

const char*	AForm::FormNotSignedException::what() const noexcept {
	return ("the form has not been signed yet!");
}