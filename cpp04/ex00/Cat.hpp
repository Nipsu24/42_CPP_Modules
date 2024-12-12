/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:42:26 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/12 15:44:33 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {
	public:
		//Constructor
		Cat();
		//Copy constructor
		Cat(const Cat& other);
		//Copy assignment operator
		Cat& operator=(const Cat& other);
		//Destructor
		~Cat();
		
		//Methods:
		void	makeSound() const override;
};

#endif