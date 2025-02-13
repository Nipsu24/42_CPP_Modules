/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/13 12:34:18 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void)
{
	MutantStack<int>	mstack;
	
	std::cout << "Insert 5 and 17 and show top of stack" << std::endl;
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	std::cout << "Remove top of stack" << std::endl;
	mstack.pop();

	std::cout << "Show size of stack" << std::endl;
	std::cout << mstack.size() << std::endl;
	std::cout << "add values 3, 5, 737 and 0" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "Check copy assignemnt operator" << std::endl;
	MutantStack<int> copyStack;
	copyStack = mstack;
	for (int copyMember : copyStack) {
		std::cout << copyMember << std::endl;
	}
	std::cout << std::endl;
	
	//+++++++++++++++list test+++++++++++++++++++++++++++++++
	
	std::cout << "Same tests as above, just with list" << std::endl;
	std::list<int>	lstack;
	
	lstack.push_back(5);
	lstack.push_back(17);

	std::cout << lstack.back() << std::endl;
	lstack.pop_back();

	std::cout << lstack.size() << std::endl;
	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	//[...]
	lstack.push_back(0);
	std::list<int>::iterator it_b = lstack.begin();
	std::list<int>::iterator ite_b = lstack.end();
	++it_b;
	--it_b;
	while (it_b != ite_b)
	{
		std::cout << *it_b << std::endl;
		++it_b;
	}
	std::list<int> l(lstack);
	return 0;
}
