/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:17:07 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/21 15:20:50 by mmeier           ###   ########.fr       */
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
void	Contact::setFirstName(const std::string& name) {
    mFirstName = name;
}

void	Contact::setLastName(const std::string& name) {
    mLastName = name;
}

void	Contact::setNickname(const std::string& name) {
    mNickname = name;
}

void	Contact::setPhoneNo(const std::string& number) {
    mPhoneNo = number;
}

void	Contact::setDarkestSecret(const std::string& secret) {
    mDarkestSecret = secret;
}
