/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:59:51 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/01 12:37:34 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : AForm("RobotomyRequestForm", 72, 45), mTarget(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {
	mTarget = other.mTarget;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	mTarget = other.mTarget;
	return (*this);
}

RobotomyRequestForm:: ~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	checkExecutionRequirements(executor);
	performRobotomy();
}

/*Seeding based on current time in sec used in order to cause rand()
  to produce different number sequences. Bool for avoiding to reseed
  as this would cause the same sequence if function is called multiple time
  during execution.*/
void RobotomyRequestForm::performRobotomy() const {
	static bool seeded = false;
	if (!seeded) {
		srand(static_cast<unsigned int>(time(nullptr)));
		seeded = true;
	}
	std::cout << "***DRILLING NOISES***" << std::endl;
	int	randomNumber = rand();
	if (randomNumber % 2)
		std::cout << "..." << mTarget << " has been robotomized successfully." << std::endl;
	else
		std::cout << "...Robotomy on " << mTarget << " failed." << std::endl;
}
