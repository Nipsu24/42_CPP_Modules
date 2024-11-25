/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:17:07 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/25 11:26:26 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*Getter functions of the Contact Class*/
std::string	Contact::getFirstName() const {return mFirstName;}

std::string	Contact::getLastName() const {return mLastName;}

std::string	Contact::getNickname() const {return mNickname;}

std::string	Contact::getPhoneNo() const {return mPhoneNo;}

std::string	Contact::getDarkestSecret() const {return mDarkestSecret;}

/*Setter functions of the Contact Class*/
void	Contact::setFirstName(std::string& name) {mFirstName = name;}

void	Contact::setLastName(std::string& name) {mLastName = name;}

void	Contact::setNickname(std::string& name) {mNickname = name;}

void	Contact::setPhoneNo(std::string& number) {mPhoneNo = number;}

void	Contact::setDarkestSecret(std::string& secret) {mDarkestSecret = secret;}
