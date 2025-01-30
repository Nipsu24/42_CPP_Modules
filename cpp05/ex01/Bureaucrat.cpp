/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:06:32 by mmeier            #+#    #+#             */
/*   Updated: 2025/01/30 15:09:56 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*Constructor*/
Bureaucrat::Bureaucrat(const std::string name, int grade)
	: mName(name), mGrade(grade) {
	if (grade < 1 )
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

/*Copy Constructor, values to be initialised via initialiser list,
  as const members must be initialised at the point of construction.*/
Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: mName(other.mName), mGrade(other.mGrade) {}
	

/*Copy assignment operator, only mGrade considered here as it is
  not const in constrast to mName*/
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this == &other)
		return (*this);
	mGrade = other.mGrade;
	return (*this);
}

/*Destructor*/
Bureaucrat:: ~Bureaucrat() {}

/*Getter function for name*/
std::string	Bureaucrat::getName() const {return (mName);}

/*Getter function for grade*/
int	Bureaucrat::getGrade() {return (mGrade);}

/*Increments grade in case it is not already 1.*/
void	Bureaucrat::incrementGrade() {
	if (mGrade <= 1)
		throw GradeTooHighException();
	mGrade--;
}

/*Decrements grade in case it is not alreay 150.*/
void	Bureaucrat::decrementGrade() {
	if (mGrade >= 150)
		throw GradeTooLowException();
	mGrade++;
}

const char*	Bureaucrat::GradeTooHighException::what() const noexcept {
	return ("Grade is too high!");
}

// Definition of GradeTooLowException's what() method
const char*	Bureaucrat::GradeTooLowException::what() const noexcept {
	return ("Grade is too low!");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& clerk) {
    os << clerk.getName();
	os << ",";
	os << " bureaucrat grade ";
	os << clerk.getGrade();
    return (os);
}

/*Catches exception from beSigned function in case the grade of a bureaucrat is too low
  to sign the form.*/
void	Bureaucrat::signForm(Form& paper) {
	try {
		paper.beSigned(*this);
		std::cout << *this << " signed form " << paper << "." << std::endl;
	}
	catch (std::exception &e) {
		std::cout << *this << " couldn't sign form " << paper << ", because " << e.what() << std::endl;
	}
}
