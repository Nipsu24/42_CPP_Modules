/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/04 11:10:49 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.cpp"

/*Uses nested try catch block in order to avoid memory leaks if exception is caught after
  memory has been allocated for the class object.*/
int	main(void) {
	
	Intern johnny;
	Bureaucrat gable("Gable", 100);
	try {
		AForm* form = johnny.makeForm("robotomy request", "Bender");
		try {
			gable.signForm(*form);
			gable.executeForm(*form);
		}
		catch (const std::exception& e) {
			delete form;
			throw;
		}
		delete form;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	
	Intern ronny;
	Bureaucrat miles("Miles", 20);
	try {
		AForm* secondForm = ronny.makeForm("presidential pardon", "Bender");
		try {
			miles.signForm(*secondForm);
			miles.executeForm(*secondForm);
		}
		catch (const std::exception& e) {
			delete secondForm;
			throw;
		}
		delete secondForm;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

std::cout << std::endl;
	std::cout << std::endl;

	
	Intern tommy;
	try {
		AForm* thirdForm = tommy.makeForm("madeup request", "Bender");
		delete thirdForm;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
