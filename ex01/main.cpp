/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:03:41 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/21 16:19:17 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phoneBook;
	std::string	input;
	
	std::cout << "PhoneBook Options (Enter either of them):\n";
	std::cout << "ADD\n";
	std::cout << "SEARCH\n";
	std::cout << "EXIT\n";
	std::getline(std::cin, input);
	while (input != "EXIT")
	{
		if (input == "ADD")
			phoneBook.addContact();
		else
			std::cout << "Error. Wrong Command\n";
		std::getline(std::cin, input);
	}
	std::cout << "EXIT PHONEBOOK\n";
	return (0);
}
