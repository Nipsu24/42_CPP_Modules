/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:21:45 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/18 15:18:27 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <stack>

class RPN {
	private:
		std::list<std::string> mList;
		std::stack<int> mStack;
	
	public:
		//constructors
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		//methods
		bool	checkForValidInput(const std::string& input);
		void	calculateResult();
};