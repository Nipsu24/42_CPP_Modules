/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:38:32 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/26 12:26:52 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*temp is arbitrary variable name (can be anything)*/
void	randomChump(std::string name)
{
	Zombie temp(name);
	temp.announce();
}
