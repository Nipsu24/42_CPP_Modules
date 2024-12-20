/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:42:26 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/16 11:03:47 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain*	mCatBrain;
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
		Brain&	getBrain();
};

#endif