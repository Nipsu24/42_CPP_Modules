/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/02 13:23:48 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.cpp"

int	main(void) {
	
	Intern johnny;
	Bureaucrat gable("Gable", 10);
	try {
		AForm* form = johnny.makeForm("robotomy request", "Bender");
		gable.executeForm(*form); // might cause leaks if exception is caught
		delete form;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	
	Intern tommy;
	try {
		AForm* form = tommy.makeForm("madeup request", "Bender");
		delete form;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
