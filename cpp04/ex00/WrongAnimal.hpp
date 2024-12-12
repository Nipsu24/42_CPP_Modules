/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:41:20 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/12 16:04:22 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string	mType;
	
	public:
		//Constructor
		WrongAnimal();
		//Copy constructor
		WrongAnimal(const WrongAnimal& other);
		//Copy assignment operator
		WrongAnimal& operator=(const WrongAnimal& other);
		/*Destructor - needs to be virtual, as this ensures that
		correct destructor is invoked when deleting an object through
		a base class pointer, starting from the most derived class and
		working way up to the base class--> adheres to key principle
		of oop: polymorphic destruction*/
		virtual ~WrongAnimal();
		
		//Methods:
		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif