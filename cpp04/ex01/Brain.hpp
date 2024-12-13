/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:06:25 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/13 16:25:40 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <array>

class Brain {
	private:
		// std::string	mIdeas[100];
		std::array<std::string, 100> mIdeas;
	
	public:
		//Constructor
		Brain();
		//Copy constructor
		Brain(const Brain& other);
		//Copy assignment operator
		Brain& operator=(const Brain& other);
		/*Destructor*/
		~Brain();
	
	//Methods:
	std::string	getIdea(int index);
	void		setIdea(int index, std::string idea);
};

#endif