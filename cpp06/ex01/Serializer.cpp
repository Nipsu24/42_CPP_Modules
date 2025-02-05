/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:27:41 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/05 14:02:56 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <fstream>

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other) {
	(void)other;
}

Serializer& Serializer::operator=(const Serializer& other) {
	if (this == &other)
		return (*this);
	return (*this);
}

Serializer::~Serializer() {}

/*Uses reinterpret casting operator in order to convert pointer into uintptr_t*/
uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}