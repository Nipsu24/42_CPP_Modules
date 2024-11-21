/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:38:58 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/21 15:19:13 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <cctype>
#include "Contact.hpp"
#include <string>
#include <iostream>

class PhoneBook {
private:
	Contact	mContacts[8];
	int		mIndex;

public:
	//Constructor
	PhoneBook() : mIndex(0) {}
	
	//Methods
	void	addContact();
    // void	searchContact();
	// void	exitPhoneBook();	
};

#endif