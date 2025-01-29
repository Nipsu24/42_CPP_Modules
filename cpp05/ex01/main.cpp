/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2025/01/29 16:28:16 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	try {
		Bureaucrat	john("John", 5);
		Form		alpha("Alpha", 4, 10);
		alpha.beSigned(john);
		std::cout << john << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat	joe("Joe", 149);
		std::cout << joe << std::endl;
		std::cout << "decrementing " << joe.getName() << "'s " << "grade" << std::endl;
		joe.decrementGrade();
		std::cout << joe << std::endl;
		std::cout << "decrementing " << joe.getName() << "'s " << "grade" << std::endl;
		joe.decrementGrade();
		std::cout << joe << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "Try to initialise class with grade 160" << std::endl;
	try {
		Bureaucrat	tom("Tom", 160);
		std::cout << tom << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "Try to initialise class with grade 0" << std::endl;
	try {
		Bureaucrat	lisa("Lisa", 0);
		std::cout << lisa << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat	amy("Amy", 1);
		std::cout << amy << std::endl;
		std::cout << "incrementing " << amy.getName() << "'s " << "grade" << std::endl;
		amy.incrementGrade();
		std::cout << amy << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (0);
}