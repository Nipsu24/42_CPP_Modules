/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/01 12:44:32 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int	main(void) {
	
	PresidentialPardonForm pardonForm("John");
	Bureaucrat president("Mr. President", 1);
	president.signForm(pardonForm);
	president.executeForm(pardonForm);
	
	std::cout << std::endl;
	std::cout << std::endl;
	
	RobotomyRequestForm roboForm("Dr. Lecter");
	Bureaucrat roboCop("RoboCop", 30);
	roboCop.signForm(roboForm);
	roboCop.executeForm(roboForm);
	
	std::cout << std::endl;
	std::cout << std::endl;

	ShrubberyCreationForm shrubberyForm("Balconia");
	Bureaucrat bulbasaur("Bulbasaur", 10);
	bulbasaur.signForm(shrubberyForm);
	bulbasaur.executeForm(shrubberyForm);

	std::cout << std::endl;
	std::cout << std::endl;
	
	PresidentialPardonForm anotherPardon("Matt");
	Bureaucrat chancelor("Chancelor", 5);
	chancelor.executeForm(anotherPardon);

	std::cout << std::endl;
	std::cout << std::endl;
	
	RobotomyRequestForm anotherRobo("Voldemort");
	Bureaucrat potter("Potter", 40);
	potter.signForm(anotherRobo);
	potter.executeForm(anotherRobo);

	std::cout << std::endl;
	std::cout << std::endl;
	
	try {
		ShrubberyCreationForm anotherShrubbery("Gadda Da Vida");
		Bureaucrat microbe("Microbe", 151);
		microbe.signForm(anotherShrubbery);
		microbe.executeForm(anotherShrubbery);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
