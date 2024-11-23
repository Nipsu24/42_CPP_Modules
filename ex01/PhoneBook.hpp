/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:38:58 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/23 12:48:56 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <cctype>
#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

class PhoneBook {
private:
	Contact	mContacts[8];
	int		mIndex;
	void	printErrorEmptyField(const std::string& field);
	int		checkForValidNumber(std::string input);
	void	printTableHeader();	
	void	printAllContacts();
	void	printContactDetails();
	void	printSingleContactInformation(int index);
	int		addContactField(std:: string& input, Contact &newContact,
				const std:: string& field, void (Contact:: *setter)(std::string&));

public:
	//Constructor
	// PhoneBook() = default; //segfaults when using this notation
	PhoneBook() : mIndex(0) {} 
	
// PhoneBook() : mIndex(3) {
//         // First contact
//         mContacts[0].setFirstName("JohnJohn243");
//         mContacts[0].setLastName("Doe");
//         mContacts[0].setNickname("Johnny");
//         mContacts[0].setPhoneNo("123-456-7890");
//         mContacts[0].setDarkestSecret("Loves pineapple");

//         // Second contact
//         mContacts[1].setFirstName("Janeflkajflkaj");
//         mContacts[1].setLastName("Smith");
//         mContacts[1].setNickname("Janie");
//         mContacts[1].setPhoneNo("987-654-3210");
//         mContacts[1].setDarkestSecret("Afraid of clowns");

//         // Third contact
//         mContacts[2].setFirstName("Alex");
//         mContacts[2].setLastName("Johnson");
//         mContacts[2].setNickname("Lexaaffaafdf");
//         mContacts[2].setPhoneNo("555-123-4567");
//         mContacts[2].setDarkestSecret("Has collecting pens");
//     }
	//Methods
	int		addContact();
    void	searchContact();
};

#endif