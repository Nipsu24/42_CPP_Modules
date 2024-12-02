/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:55:43 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/02 14:50:16 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int					value;
		static const int	fractionalBitsAmount;
	
	public:
		//Constructor
		Fixed();
		//Copy constructor
		/*needed e.g. for "deep copies" of pointers
		  (copying content the pointer is pointing to and not the pointer
		  itself as this would end up with two objects calling delete on same
		  non-null pointer and thus to heap corruption)*/
		Fixed(const Fixed& other);
		//Copy assignment operator
		Fixed& Fixed::operator=(const Fixed& other);
		//Deconstructor
		~Fixed();
		
		//Methods:
		int		getRawBits(void) const;
		void	setRawBits(int const raw);	
		
};

#endif

