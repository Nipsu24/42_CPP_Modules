/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:21:32 by mmeier            #+#    #+#             */
/*   Updated: 2024/12/09 14:15:03 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*constructor*/
Fixed::Fixed() : mRawBits(0) {
	// std::cout << "Default constructor called" << std::endl;
}

//Parameterized constructor I (int)
Fixed::Fixed(const int n){
	// std::cout << "Int constructor called" << std::endl;
	mRawBits = n * (1 << mFractionalBitsAmount);
}

//Parameterized constructor II (float)
Fixed::Fixed(const float n){
	// std::cout << "Float constructor called" << std::endl;
	mRawBits = static_cast<int>(roundf(n * (1 << mFractionalBitsAmount)));
}

/*copy-constructor, takes as argument already existing class object*/
Fixed::Fixed(const Fixed& other){
	// std::cout << "Copy constructor called" << std::endl;
	mRawBits = other.getRawBits();
}

/*copy assignment operator, defines how object attributes should be 
  populated from copied class*/
Fixed& Fixed::operator=(const Fixed& other){
	if (this == &other)
		return (*this);
	// std::cout << "Copy assignment operator called" << std::endl;
	mRawBits = other.getRawBits();
	return (*this);
}

/*deconstructor*/
Fixed::~Fixed(){
	// std::cout << "Destructor called " << std::endl;
}

/*Returns value of member variable rawBits (fixed-point representation of a number).
  Fixed point representation of e.g. 2.75 is 2.75 X 256 = 704)*/
int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (mRawBits);
}

/*Can set member variable mRawBits value (fixed-point representation of a number).*/
void	Fixed::setRawBits(int const raw)
{
	 mRawBits = raw;
}

/*Converts fixed-point representation to float.
  1 << 8 is equal to 2^8 (binary: 100000000) which is 256 in decimal*/
float	Fixed::toFloat(void) const
{
	float	floatValue;

	floatValue = static_cast<float>(mRawBits) / (1 << mFractionalBitsAmount); 
	return (floatValue);
}

/*Converts fixed-point representation to integer. 
  int = rounded (rawBits/256)*/
int	Fixed::toInt(void) const
{
	int	intValue;

	intValue = roundf(mRawBits / (1 << mFractionalBitsAmount));
	return (intValue);
}

/*Overload stream insertion operator which enables to send instance of Fixed
  class to output stream (std::cout). Takes as parameter output stream, where
  data will be written and Class object. In the function body, the fixed object
  calls toFloat()function which converts fixed-point number to floating point
  and inserts value into output stream os with << operator. Returns os by
  reference which allows chaining of stream operations*/
  
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return (os);
}

/*Populates mRawBits of new Fixed class object 'result' with sum of mRawBits of the object
  and the mRawBits of the passed class object. Overloaded operator '<<' (see function above)
  converts the fixed-point result into float representation.*/
Fixed	Fixed::operator+(const Fixed& fixed)
{
	Fixed	result;
	
	result.setRawBits(this->mRawBits + fixed.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed& fixed)
{
	Fixed	result;
	
	result.setRawBits(this->mRawBits - fixed.getRawBits());
	return (result);
}

/*Right bitshift operation devides result by 2^fractional bit amount in order to adjust
  it back to fixed-point scale (as result is initially scaled twice due to each operant
  by 2^fractional bit amount).*/
Fixed	Fixed::operator*(const Fixed& fixed)
{
	Fixed		result;
	long long	rawResult = static_cast<long long>(this->mRawBits) * fixed.getRawBits();
	result.setRawBits(static_cast<int>(rawResult >> mFractionalBitsAmount));
	return (result);
}

/*Left bitshift before devision to ensure that numerator is properly scaled to maintain fractional precision.
  e.g. 512 w/o leftshift:512/256 = 2, w. leftshift: (512 * 256) / 256 = 512 -> fractional part is preserved.*/
Fixed	Fixed::operator/(const Fixed& fixed)
{
	Fixed		result;
	long long	rawResult = (static_cast<long long>(this->mRawBits) << mFractionalBitsAmount) / fixed.getRawBits();
	result.setRawBits(static_cast<int>(rawResult));
	return (result);
}

/*prefix increment, increments value by 1/256 (0.00390625)
  Returns reference to the current object.*/
Fixed& Fixed::operator++()
{
	this->mRawBits++;
	return (*this);
}

/*postfix increment, increments value by 1/256 (0.00390625)
 Not returned as reference, as it returns temporary object and not a reference
  to a current object */
Fixed Fixed::operator++(int)
{
	Fixed	temp = *this;
	this->mRawBits++;
	return (temp);
}

/*prefix decrement, decrements value by 1/256 (0.00390625)*/
Fixed& Fixed::operator--()
{
	this->mRawBits--;
	return (*this);
}

/*postfix decrement, decrements value by 1/256 (0.00390625)*/
Fixed Fixed::operator--(int)
{
	Fixed	temp = *this;
	this->mRawBits--;
	return (temp);
}

/*Overloads operators: >, <, <=, >=, ==, !=, functions return 'true (1)' or 'false (0)' depending if
  the conditions are met.*/
bool	Fixed::operator>(const Fixed& other) const{return (mRawBits > other.mRawBits);}

bool	Fixed::operator<(const Fixed& other) const{return (mRawBits < other.mRawBits);}

bool	Fixed::operator<=(const Fixed& other) const{return (mRawBits <= other.mRawBits);}

bool	Fixed::operator>=(const Fixed& other) const{return (mRawBits >= other.mRawBits);}

bool	Fixed::operator==(const Fixed& other) const{return (mRawBits == other.mRawBits);}

bool	Fixed::operator!=(const Fixed& other) const{return (mRawBits != other.mRawBits);}

Fixed&	Fixed::min(Fixed& fixedA, Fixed& fixedB)
{
	if (fixedA <= fixedB)
		return (fixedA);
	else
		return (fixedB);
}

const Fixed&	Fixed::min(const Fixed& fixedA, const Fixed& fixedB)
{
	if (fixedA <= fixedB)
		return (fixedA);
	else
		return (fixedB);
}

Fixed&	Fixed::max(Fixed& fixedA, Fixed& fixedB)
{
	if (fixedA >= fixedB)
		return (fixedA);
	else
		return (fixedB);
}

const Fixed&	Fixed::max(const Fixed& fixedA, const Fixed& fixedB)
{
	if (fixedA >= fixedB)
		return (fixedA);
	else
		return (fixedB);
}