/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:38:32 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/26 16:38:58 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*Creates zombie class on the stack. 'temp' is an arbitrary variable name.*/
void	randomChump(std::string name)
{
	Zombie temp(name);
	temp.announce();
}
