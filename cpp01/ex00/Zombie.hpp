/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:38:39 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/26 13:57:58 by mmeier           ###   ########.fr       */
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
	Zombie(std::string zombieName);
	//Deconstructor
	~Zombie();
	//Methods (public)
    void	announce(void);
};

#endif