/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:33:47 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/24 11:31:29 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
	private:
	std::vector<int>				mVecArr;
	std::deque<int>					mDeqArr;
	std::vector<std::vector<int>>	mNumberPairs;
	int								mRecursionLevel;
	
	public:
		//constructors:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		//methods:
		bool	checkValidInput(std::vector<std::string>& input);
		void	mergeSortVector();
		void	splitInitiallyIntoPairsVector();
		void	sortRecursively(std::vector<std::vector<int>> input);
		// void	mergeSortDeque();
};

std::ostream& operator<<(std::ostream& os, std::vector<int>& printVec);