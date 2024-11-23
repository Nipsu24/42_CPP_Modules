/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:17:07 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/23 12:36:47 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string	Contact::getFirstName() const {
    return mFirstName;
}

std::string	Contact::getLastName() const {
    return mLastName;
}

std::string	Contact::getNickname() const {
    return mNickname;
}

std::string	Contact::getPhoneNo() const {
    return mPhoneNo;
}

std::string	Contact::getDarkestSecret() const {
    return mDarkestSecret;
}

// Setters
void	Contact::setFirstName(std::string& name) {
    mFirstName = name;
}

void	Contact::setLastName(std::string& name) {
    mLastName = name;
}

void	Contact::setNickname(std::string& name) {
    mNickname = name;
}

void	Contact::setPhoneNo(std::string& number) {
    mPhoneNo = number;
}

void	Contact::setDarkestSecret(std::string& secret) {
    mDarkestSecret = secret;
}
