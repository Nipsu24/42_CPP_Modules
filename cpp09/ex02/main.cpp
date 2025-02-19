/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:43:32 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/19 11:21:40 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

/*Checks for insufficient arguments passed to function, converts argument into string array and
  passes it to member functions for further processing.*/
int main(int ac, char* av[]) {
	if (ac < 3) {
		std::cerr << "Error. Insufficient arguments passed to program." << std::endl;
		return (1);
	}
	std::vector<std::string> input(ac - 1); //needed if not used input.push_back(av[i+1]) in for loop
	for (auto i = 0; i < ac - 1; i++) {
		input[i] = av[i + 1];
	}
	PmergeMe mergeSorter;
	if (!mergeSorter.checkValidInput(input))
		return (1);
	mergeSorter.mergeSortVector();
	return (0);
}
