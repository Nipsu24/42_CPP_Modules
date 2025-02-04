/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:06:32 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/04 10:52:27 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

/*Constructor*/
Intern::Intern() {}

/*Copy Constructor, values to be initialised via initialiser list,
  as const members must be initialised at the point of construction.*/
Intern::Intern(const Intern& other) {
	(void)other;
}
	

/*Copy assignment operator, only mGrade considered here as it is
  not const in constrast to mName*/
Intern& Intern::operator=(const Intern& other) {
	if (this == &other)
		return (*this);
	return (*this);
}

/*Destructor*/
Intern:: ~Intern() {}

/*Uses switch statement in order to check whether passed name for a form exist. If not the case,
  throws exception. If memory allocation fails, prints respective message and returns nullpointer.*/
AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	
	int	formCode = -1;
	const std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i <  3; i++) {
		if (formNames[i] == formName)
			formCode = i;
	}

	try {
		switch(formCode)
		{
			case 0:
				std::cout << "Intern creates "	<< formName << " targeted on " << target << "." << std::endl;
				return (new ShrubberyCreationForm(target));
			case 1:
				std::cout << "Intern creates "	<< formName << " targeted on " << target << "." << std::endl;
				return (new RobotomyRequestForm(target));
			case 2:
				std::cout << "Intern creates "	<< formName << " targeted on " << target << "." << std::endl;
				return (new PresidentialPardonForm(target));
			default:
				throw FormDoesNotExistException();
		}	
	}
	catch (std::bad_alloc& e) {
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		return nullptr;
	}
}

const char* Intern::FormDoesNotExistException::what() const noexcept {
	return ("The Form does not exist!");
}
