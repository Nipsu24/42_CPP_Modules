/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:38:58 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/22 14:58:21 by mmeier           ###   ########.fr       */
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
	// PhoneBook() = default; //segfaults when using this notation
	PhoneBook() : mIndex(0) {} 
	
	//Methods
	void	addContact();
	void	addContactField(std:: string& input, Contact &newContact,
				const std:: string& field, void (Contact:: *setter)(std::string&));
	void	printErrorEmptyField(const std::string& field);
	int	checkForValidNumber(std::string input);
    // void	searchContact();
	// void	exitPhoneBook();	
};

#endif