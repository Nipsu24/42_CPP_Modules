/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:38:39 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/25 16:08:12 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
	std::string	name; 
	
	//Methods (private)
	//TBD
	
public:
	
	//Constructor
	Zombie() = default;
	~Zombie(){
		std::cout << "Zombie " << name << " has been destroyed\n" ;
	}
	//Methods (public)
    void	announce(void);
	Zombie *newZombie(std::string name);
	void	randomChump(std::string name);
};

#endif