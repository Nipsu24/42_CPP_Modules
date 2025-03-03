/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:43:32 by mmeier            #+#    #+#             */
/*   Updated: 2025/03/03 10:48:12 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <chrono>
#include <iomanip>

/*Checks for insufficient arguments passed to function, converts argument into vector and deque array and
  passes it to the member functions for further processing. Checks time of processing needed for both types
  of arrays*/
int main(int ac, char* av[]) {
	if (ac < 3) {
		std::cerr << "Error. Insufficient arguments passed to program." << std::endl;
		return (1);
	}
	PmergeMe mergeSorter;
	auto startVec = std::chrono::high_resolution_clock::now();
	std::vector<std::string> inputVec(ac - 1);
	for (auto i = 0; i < ac - 1; i++) {
		inputVec[i] = av[i + 1];
	}
	if (!mergeSorter.checkValidInputVector(inputVec))
		return (1);
	mergeSorter.mergeSortVector();
	auto stopVec = std::chrono::high_resolution_clock::now();
	auto durationVec = std::chrono::duration<double, std::micro>(stopVec - startVec);
	std::cout << "Time to process a range of " << mergeSorter.getVectorSize() << " elements with std::vector : "
								<< std::fixed << std::setprecision(0) << durationVec.count() << " μs" << std::endl;
	

	auto startDeq = std::chrono::high_resolution_clock::now();
	std::deque<std::string> inputDeq(ac - 1);
	for (auto i = 0; i < ac - 1; i++) {
		inputDeq[i] = av[i + 1];
	}
	if (!mergeSorter.checkValidInputDeque(inputDeq))
		return (1);
	mergeSorter.mergeSortDeque();
	auto stopDeq = std::chrono::high_resolution_clock::now();
	auto durationDeq = std::chrono::duration<double, std::micro>(stopDeq - startDeq);
	std::cout << "Time to process a range of " << mergeSorter.getDequeSize() << " elements with std::deque : "
								<< std::fixed << std::setprecision(0) << durationDeq.count() << " μs" << std::endl;
	return (0);
}
