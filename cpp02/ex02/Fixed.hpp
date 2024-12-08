/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:55:43 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/08 18:15:15 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include "iomanip"
#include <cmath>

class Fixed {
	private:
		int					mRawBits;
		static const int	mFractionalBitsAmount = 8;
	
	public:
		//Constructor
		Fixed();
		//Parameterized constructor I
		Fixed(const int n);
		//Parameterized constructor II
		Fixed(const float n);
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
		
		float	toFloat(void) const;
		int		toInt(void) const;

		Fixed	operator+(const Fixed& fixed);
		Fixed	operator-(const Fixed& fixed);
		Fixed	operator*(const Fixed& fixed);
		Fixed	operator/(const Fixed& fixed);

		Fixed&	operator++();
		Fixed	operator++(int);

		Fixed&	operator--();
		Fixed	operator--(int);

		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		static Fixed&	min(Fixed& fixedA, Fixed& fixedB);
		static const Fixed&	min(const Fixed& fixedA, const Fixed& fixedB);
		static Fixed&	max(Fixed& fixedA, Fixed& fixedB);
		static const Fixed&	max(const Fixed& fixedA, const Fixed& fixedB);
		
		// bool	operator<(const Fixed& other);
		// bool	operator>=(const Fixed& other);
		// bool	operator<=(const Fixed& other);
		// bool	operator==(const Fixed& other);
		// bool	operator!=(const Fixed& other);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
