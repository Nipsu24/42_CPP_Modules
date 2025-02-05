/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:25:43 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/05 14:28:18 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Struct.hpp"

int	main(void) {
	Data data;
	data.firstStr = "Hello";
	data.secondStr = "World";
	std::cout << "Before serialising:" << std::endl;
	// std::cout << &data << std::endl;
	std::cout << data.firstStr << std::endl;
	std::cout << data.secondStr << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	Data* dataDesirialised = Serializer::deserialize(raw);
	std::cout << "After deserialising:" << std::endl;
	// std::cout << &dataDesirialised << std::endl;
	std::cout << dataDesirialised->firstStr << std::endl;
	std::cout << dataDesirialised->secondStr << std::endl;
}
