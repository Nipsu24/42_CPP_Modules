/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:41:20 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/12 15:59:08 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string	mType;
	
	public:
		//Constructor
		Animal();
		//Copy constructor
		Animal(const Animal& other);
		//Copy assignment operator
		Animal& operator=(const Animal& other);
		/*Destructor - needs to be virtual, as this ensures that
		correct destructor is invoked when deleting an object through
		a base class pointer, starting from the most derived class and
		working way up to the base class--> adheres to key principle
		of oop: polymorphic destruction*/
		virtual ~Animal();
		
		//Methods:
		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif