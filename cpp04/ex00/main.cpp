/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/16 12:12:44 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	{
		std::cout << "+++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << "+++++++++++++01 TEST+++++++++++++++++++++++" << std::endl;
		std::cout << "+++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		const	Animal* meta = new Animal();
		const	Animal* j = new Dog();
		const	Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		j->makeSound();
		i->makeSound();
		meta->makeSound();
		delete j;
		delete i;
		delete meta;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		std::cout << "+++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << "+++++++++++++02 TEST+++++++++++++++++++++++" << std::endl;
		std::cout << "+++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		const	WrongAnimal* meta = new WrongAnimal();
		const	Animal* j = new Dog();
		const	WrongAnimal* i = new WrongCat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		j->makeSound();
		i->makeSound();
		meta->makeSound();
		delete j;
		delete i;
		delete meta;
	}
	return (0);
}