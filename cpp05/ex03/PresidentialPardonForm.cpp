/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:59:51 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/01 12:13:33 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    : AForm("PresidentialPardonForm", 25, 5), mTarget(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {
	mTarget = other.mTarget;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	mTarget = other.mTarget;
	return (*this);
}

PresidentialPardonForm:: ~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	checkExecutionRequirements(executor);
	performPardon();
}

void PresidentialPardonForm::performPardon() const {
	std::cout << mTarget << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}