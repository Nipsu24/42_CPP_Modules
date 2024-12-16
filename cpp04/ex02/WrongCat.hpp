/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:42:26 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/12 16:13:24 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		//Constructor
		WrongCat();
		//Copy constructor
		WrongCat(const WrongCat& other);
		//Copy assignment operator
		WrongCat& operator=(const WrongCat& other);
		//Destructor
		~WrongCat();
};

#endif