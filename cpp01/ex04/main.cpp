/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:57:55 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/28 11:25:54 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(int ac, char **av)
{
	
	(void)av;
	if (ac != 4)
	{
		std::cout << "Error. Insufficient argument amount." << std::endl;
		std::cout << "Allowed argument amount is '3' in the following order:"<< std::endl;
		std::cout << "filename, string1, string2." << std::endl;
	}
	else
		std::cout << "Correct amount." << std::endl;
	return (0);
}
