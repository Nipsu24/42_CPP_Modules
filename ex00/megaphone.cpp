/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:33:55 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/25 12:09:07 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*First converst c-string to std::string, then converts each char in string
  via std::toupper to capital chars and prints string via std::cout. In case
  arg is not last arg, spaces are printed in bewtween of args, otherwise
  prints newline character.*/
int main(int ac, char **av)
{
	if (ac > 1) {
		for (int j = 1; j < ac; j++)
		{
			std::string argument = av[j];
			for (size_t i = 0; i < argument.length(); i++)
			{
				argument[i] = std::toupper(argument[i]);
			}
			std::cout << argument;
			if (j != ac - 1)
				std::cout << " ";
			else
				std::cout << "\n";
		}
	} 
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	return (0);
}

// #include <iostream>
// #include <string.h>

// int	main(int ac, char **av)
// {
// 	if (ac > 1){
// 		for (int j = 1; j < ac; j++){
// 			for(size_t i = 0; i <= strlen(av[j]); i++){
// 			av[j][i] = toupper(av[j][i]);
// 			std::cout << av[j][i];
// 			}	
// 			if (j != ac -1)
// 				std::cout << " ";
// 			else
// 				std::cout << "\n";
// 		}
// 	}
// 	else
// 		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
// 	return (0);
// }
