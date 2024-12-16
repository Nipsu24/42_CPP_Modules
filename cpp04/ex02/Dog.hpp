/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:42:05 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/16 11:03:37 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain*	mDogBrain;
	public:
		//Constructor
		Dog();
		//Copy constructor
		Dog(const Dog& other);
		//Copy assignment operator
		Dog& operator=(const Dog& other);
		//Destructor
		~Dog();
		
		//Methods:
		void		makeSound() const override;
		Brain&		getBrain();
};

#endif