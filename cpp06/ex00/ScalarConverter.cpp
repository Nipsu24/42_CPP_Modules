/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:40:57 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/04 16:57:48 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>
#include <string>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	if (this == &other)
		return (*this);
	return (*this);
}

ScalarConverter:: ~ScalarConverter() {}


bool	handleChar(const std::string& literal) {
	if (literal.length() == 1 && std::isalpha(literal[0]) && std::isprint(literal[0])) {
		char c = literal[0];
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		return (true);
	}
	return (false);
}

void	handleInt(const std::string& literal) {
	try {
		int nbr = std::stoi(literal);
		char c = nbr;
		if (!std::isprint(c)) {
			std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: " << c << std::endl;
		std::cout << "int: " << nbr << std::endl;
		std::cout << "float: " << static_cast<float>(nbr) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(nbr) << ".0" << std::endl;
	}
    catch (const std::out_of_range& e) {
        std::cout << "int: not possible "  << e.what() << std::endl;
    }
}

bool	handlePseudoLiterals(const std::string& literal) {
	if (literal == "nan" || literal == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std:: endl;
		std::cout << "double: nan" << std::endl;
		return (true);
	}
	if (literal == "-inf" || literal == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std:: endl;
		std::cout << "double: -inf" << std::endl;
		return (true);
	}
	else if (literal == "+inf" || literal == "+inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std:: endl;
		std::cout << "double: +inf" << std::endl;
		return (true);
	}
	return (false);
}

void	handleFloatsAndDoubles(const std::string& literal) {
	try {
		if (handlePseudoLiterals(literal))
			return ;
		std::string cleanLiteral = literal;
		if (cleanLiteral.back() == 'f')
			cleanLiteral.pop_back();
		double value = std::stod(cleanLiteral);
		char c = static_cast<int>(value); //needed as double cannot be directly cast to char
		if (!std::isprint(c)) {
			std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: " << c << std::endl;
		if (value > static_cast<double>(std::numeric_limits<int>::max()) || value < static_cast<double>(std::numeric_limits<int>::min()))
			std::cout << "int: impossible" << std::endl;
		else 
			std::cout << "int: " << static_cast<int>(value) << std::endl;
		std::cout << "float: " << std::to_string(static_cast<float>(value)) + "f" << std::endl;
		std::cout << "double: " << std::to_string(value) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "double: not possible " << e.what() << std::endl;
	}
}

bool isNumeric(const std::string& literal) {
	size_t	j = 0;
	if (literal[0] == '-')
		j++;
	for (size_t i = j; i < literal.length(); i++) {
		if (!std::isdigit(literal[i]))
			return (false);
	}
	return (true);
}

void	ScalarConverter::convert(const std::string& literal) {
	if (literal.empty()) {
		std::cout << "String passed to function is empty." << std::endl;
		return ;
	}
	if (handleChar(literal))
		return ;
	else if (isNumeric(literal)) {
		handleInt(literal);
	}
	else {
		handleFloatsAndDoubles(literal);
	}
}
