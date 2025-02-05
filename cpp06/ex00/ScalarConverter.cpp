/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:40:57 by mmeier            #+#    #+#             */
/*   Updated: 2025/02/05 14:34:08 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>
#include <string>
#include <iomanip>

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

/*Checks if literal consists of one character and if this is printable. Then cast it to the respective datatypes*/
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

/*Hanldes the respective pseudo literals.*/
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
	else if (literal == "+inf" || literal == "+inff"
			|| literal == "inf" || literal == "inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std:: endl;
		std::cout << "double: +inf" << std::endl;
		return (true);
	}
	return (false);
}

/*Converts literal to int with stoi and catches possible exceptions. Checks also, if the resulting
  number is a printable ascii character.*/
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
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(nbr) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(nbr) << std::endl;
	}
    catch (const std::out_of_range& e) {
        std::cout << "int: not possible "  << e.what() << std::endl;
    }
	catch (const std::invalid_argument& e) {
		std:: cout << "int: not possible " << e.what() << std::endl;
	}
}

/*Trims string by removing 'f', then converts it to float and casts it to the respective datatypes. Checks
  if char is displayable character (before casting to int is needed) and if value is within int min/max. 
  Possible exception resulting from stof are caught. Digits for floats and doubles are set to 1 digit after '.'*/
void	handleFloats(const std::string& literal) {
	try {
		std::string cleanLiteral = literal;
		cleanLiteral.pop_back();
		float value = std::stof(cleanLiteral);
		char c = static_cast<int>(value);
		if (!std::isprint(c)) {
			std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: " << c << std::endl;
		if (value > static_cast<float>(std::numeric_limits<int>::max()) || value < static_cast<float>(std::numeric_limits<int>::min()))
			std::cout << "int: impossible" << std::endl;
		else 
			std::cout << "int: " << static_cast<int>(value) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << value << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(value) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "float: not possible " << e.what() << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std:: cerr << "float: not possible " << e.what() << std::endl;
	}
}

/*Converts literal to double, possible exceptions caught in try/catch statement. Digits for floats and doubles
  are set to 1 digit after '.'*/
void	handleDoubles(const std::string& literal) {
	try {
		double value = std::stod(literal);
		char c = static_cast<int>(value);
		if (!std::isprint(c)) {
			std::cout << "char: Non displayable" << std::endl;
		}
		else
			std::cout << "char: " << c << std::endl;
		if (value > static_cast<double>(std::numeric_limits<int>::max()) || value < static_cast<double>(std::numeric_limits<int>::min()))
			std::cout << "int: impossible" << std::endl;
		else 
			std::cout << "int: " << static_cast<int>(value) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
		std::cout << "double: " << value << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "double: not possible " << e.what() << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std:: cerr << "double: not possible " << e.what() << std::endl;
	}
}

/*Checks first for empty strings, then checks if string only consists of one char. Afterwards
  checks the pseudo literals. Int is identified by abscence of '.', float by 'f' at end of string,
  otherwise it is assumed that argument is a double.*/
void	ScalarConverter::convert(const std::string& literal) {
	if (literal.empty()) {
		std::cout << "String passed to function is empty." << std::endl;
		return ;
	}
	if (handleChar(literal))
		return ;
	if (handlePseudoLiterals(literal))
		return ;
	else if (literal.find('.') == std::string::npos)
		handleInt(literal);
	else if (literal.back() == 'f')
		handleFloats(literal);
	else
		handleDoubles(literal);
}
