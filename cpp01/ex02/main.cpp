/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:38:18 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/27 11:47:22 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	phrase = "HI THIS IS BRAIN.";
	std::string* phrasePtr = &phrase;
	std::string& phraseRef = phrase;

	std::cout << "Memory address of string variable: " << &phrase << std::endl;
	std::cout << "Memory address of string pointer: " << phrasePtr << std::endl;
	std::cout << "Memory address of string reference: " << &phraseRef << std::endl;
	std::cout << std::endl;
	std::cout << "Value of string variable: " << phrase << std::endl;
	std::cout << "Value of string pointer: " << *phrasePtr << std::endl;
	std::cout << "Value of string reference: " << phraseRef << std::endl;

	return (0);
}
