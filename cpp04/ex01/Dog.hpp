/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:42:05 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/13 16:29:07 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain	*DogBrain;
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