/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/16 12:12:14 by mmeier           ###   ########.fr       */
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
	std::cout << std::endl;
	std::cout << std::endl;
	{
		std::cout << "+++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		std::cout << "+++++++++++++03 TEST+++++++++++++++++++++++" << std::endl;
		std::cout << "+++++++++++++++++++++++++++++++++++++++++++" << std::endl;
		int i;
		Animal** meta = new Animal*[10];
		for(i = 0; i < 5; i++)
			meta[i] = new Dog();
		for(i = 5; i < 10; i++)
			meta[i] = new Cat();
		std::cout << meta[2]->getType() << " " << std::endl;
		std::cout << meta[6]->getType() << " " << std::endl;
		meta[2]->makeSound();
		meta[6]->makeSound();
		std::cout << "++++++++++++++Normal Dog++++++++++++++" << std::endl;
		static_cast<Dog*>(meta[2])->getBrain().setIdea(0, "I want food!");
		static_cast<Dog*>(meta[2])->getBrain().getIdea(0);
		std::cout << "Address of normal dog brain: " << &static_cast<Dog*>(meta[2])->getBrain() << std::endl;
		std::cout << "++++++++++++++Copy Dog++++++++++++++" << std::endl;
		Dog copyDog(*static_cast<Dog*>(meta[2])); // *static Dereferences the Dog* pointer to get the object itself.
		copyDog.getBrain().getIdea(0);
		std::cout << "Address of copy dog brain: " << &copyDog.getBrain() << std::endl;
		std::cout << "++++++++++++++Copy Dog set idea++++++++++++++" << std::endl;
		copyDog.getBrain().setIdea(0, "I want mooooore fooooood!");
		copyDog.getBrain().getIdea(0);
		std::cout << "Address of copy dog brain: " << &copyDog.getBrain() << std::endl;
		std::cout << "++++++++++++++Normal Dog++++++++++++++" << std::endl;
		static_cast<Dog*>(meta[2])->getBrain().getIdea(0);
		std::cout << "Address of normal dog brain: " << &static_cast<Dog*>(meta[2])->getBrain() << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "++++++++++++++Normal Cat++++++++++++++" << std::endl;
		static_cast<Cat*>(meta[6])->getBrain().setIdea(0, "I want to hunt some mice!");
		static_cast<Cat*>(meta[6])->getBrain().getIdea(0);
		std::cout << "Address of normal cat brain: " << &static_cast<Cat*>(meta[6])->getBrain() << std::endl;
		std::cout << "++++++++++++++Copy Cat++++++++++++++" << std::endl;
		Cat copyCat(*static_cast<Cat*>(meta[6])); // *static Dereferences the Cat* pointer to get the object itself.
		copyCat.getBrain().getIdea(0);
		std::cout << "Address of copy cat brain: " << &copyCat.getBrain() << std::endl;
		std::cout << "++++++++++++++Copy Cat set idea++++++++++++++" << std::endl;
		copyCat.getBrain().setIdea(0, "I want to sleep!");
		copyCat.getBrain().getIdea(0);
		std::cout << "Address of copy cat brain: " << &copyCat.getBrain() << std::endl;
		std::cout << "++++++++++++++Normal Cat++++++++++++++" << std::endl;
		static_cast<Cat*>(meta[6])->getBrain().getIdea(0);
		std::cout << "Address of normal cat brain: " << &static_cast<Cat*>(meta[6])->getBrain() << std::endl;
		
		
		for(i = 0; i < 10; i++)
			delete meta[i];
		delete[] meta;
	}
	return (0);
}