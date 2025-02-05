/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/05 21:05:22 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(void) {
	Base base;
	
	Base* newClass = base.generate();
	Base* anotherClass = nullptr;
	base.identify(newClass);
	base.identify(*newClass);
	base.identify(anotherClass);
	delete newClass;
	return (0);
}
