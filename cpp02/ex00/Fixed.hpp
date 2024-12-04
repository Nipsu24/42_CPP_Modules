/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:55:43 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/04 11:13:04 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int					mRawBits; // represents fixed-point value (e.g. 5.25 is stored in 5.25 x 256 = 1344)
		static const int	mFractionalBitsAmount = 8;
	
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
		Fixed& operator=(const Fixed& other);
		//Destructor
		~Fixed();
		
		//Methods:
		int		getRawBits(void) const;
		void	setRawBits(int const raw);	
		
};

#endif

