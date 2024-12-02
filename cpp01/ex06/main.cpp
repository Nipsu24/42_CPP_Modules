/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:57:55 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/02 12:52:07 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl harlBot;
	
	if (ac != 2)
	{
		std::cout << "Error. Invalid argument count. One argument must be passed to program.\n";
		return (1);
	}
	harlBot.complain(av[1]);
	return (0);
}