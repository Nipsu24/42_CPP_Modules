/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2025/01/31 15:28:02 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int	main(void) {
	
	ShrubberyCreationForm form("home");
	RobotomyRequestForm("John");
	RobotomyRequestForm("Tom");
	PresidentialPardonForm("Mike");
	
	// try {
	// 	Bureaucrat	john("John", 5);
	// 	Form		alpha("Alpha", 4, 10);
	// 	john.signForm(alpha);
	// }
	// catch (const std::exception& e) {
	// 	std::cerr << "Exception: " << e.what() << std::endl;
	// }
	
	// try {	
	// 	Bureaucrat	dave("Dave", 2);
	// 	Form 		beta("Beta", 7, 50);
	// 	dave.signForm(beta);
	// }
	// catch (const std::exception& e) {
	// 	std::cerr << "Exception: " << e.what() << std::endl;
	// }
	
	// try {
	// 	Bureaucrat	ann("Ann", 0);
	// 	Form		gamma("Gamma", 8, 100);
	// 	ann.signForm(gamma);
	// }
	// catch (const std::exception& e) {
	// 	std::cerr << "Exception: " << e.what() << std::endl;
	// }

	// try {
	// 	Bureaucrat	peter("Peter", 151);
	// 	Form		delta("Delta", 8, 100);
	// 	peter.signForm(delta);
	// }
	// catch (const std::exception& e) {
	// 	std::cerr << "Exception: " << e.what() << std::endl;
	// }

}
