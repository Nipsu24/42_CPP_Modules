/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:33:55 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/14 15:46:50 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string.h>

int	main(int ac, char **av)
{
	if (ac > 1){
		for (int j = 1; j < ac; j++){
			for(size_t i = 0; i <= strlen(av[j]); i++){
			av[j][i] = toupper(av[j][i]);
			std::cout << av[j][i];
			}	
			if (j != ac -1)
				std::cout << " ";
			else
				std::cout << "\n";
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	return (0);
}
