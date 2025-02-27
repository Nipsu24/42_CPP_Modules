/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:33:47 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/27 14:04:54 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
	private:
		std::vector<int>				mVecArr;
		std::vector<int>				mVecArrLarge;
		std::vector<int>				mVecArrSmall;
		std::deque<int>					mDeqArr;
		std::deque<int>					mDeqArrLarge;
		std::deque<int>					mDeqArrSmall;
	
	public:
		//constructors:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		//methods:
		size_t				getVectorSize();
		size_t				getDequeSize();
		void				mergeSortDeque();
		void				mergeSortVector();
		bool				checkValidInputVector(std::vector<std::string>& input);
		bool				checkValidInputDeque(std::deque<std::string>& input);
		void				jacobsthalInsertionVec(std::vector<int>& large, std::vector<int>& small);
		void				jacobsthalInsertionDeq(std::deque<int>& large, std::deque<int>& small);
		void				sortRecursivelyVec(std::vector<int>& vecArr, int n);
		void				sortRecursivelyDeq(std::deque<int>& deqArr, int n);
		void				splitIntoSmallAndLargeVec();
		void				splitIntoSmallAndLargeDeq();
		std::vector<int>	generateJacobsthalNumbersVec(int n);
		std::deque<int>		generateJacobsthalNumbersDeq(int n);
};
