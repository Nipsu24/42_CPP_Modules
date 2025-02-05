/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:03:43 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/05 21:07:41 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base:: ~Base() {}

/*Modulo 3 and 2 used in order to create 33,3% probability, returns
  pointer to either A, B, or C class object.*/
Base*	Base::generate(void) {
	Base base;
	static bool seeded = false;
	if (!seeded) {
		srand(static_cast<unsigned int>(time(nullptr)));
		seeded = true;
	}
	int	randomNumber = rand();
	if (randomNumber % 3) {
		if (randomNumber % 2) {
			A* aClass = new A;
			return (static_cast<Base*>(aClass));
		}
		else {
			B* bClass = new B;
			return (static_cast<Base*>(bClass));
		}
	}
	else {
		C* cClass = new C;
		return (static_cast<Base*>(cClass));
	}
	
}

/*Dynamic cast checks actual type of the object pointed to by the base pointer p. If type match,
  returns non-nullptr in if statement and therefore does not need any try/catch statement.*/
void	Base::identify(Base* p) {
	if (p == nullptr) {
		std::cout << "Base pointer is nullptr" << std::endl;
		return ;
	}
	else if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	}
	else
		std::cout << "Unknown Type" << std::endl;
}

/*try/catch statements needed as in contrast to function above, cannot check for nullptr.
  each statement is excecuted independently if previous statement caught exception.*/
void	Base::identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {}
	
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {}
	
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::bad_cast&) {}
	std::cout << "Unknown Type" << std::endl;
}
