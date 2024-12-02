/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:38:39 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/02 12:47:07 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
	std::string	name; 
	
public:
	
	//Constructor
	Zombie();
	//Deconstructor
	~Zombie();
	//Methods (public)
    void	announce(void);
	void	setName(const std::string& zombieNamme);
};

#endif