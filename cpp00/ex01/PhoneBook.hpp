/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:38:58 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/26 14:03:48 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook {
private:
	Contact	mContacts[8];
	int		mIndex;
	
	//Methods (private)
	void	printErrorEmptyField(const std::string& field);
	int		checkForValidNumber(std::string input);
	void	printTableHeader();	
	void	printAllContacts();
	void	printContactDetails();
	void	printSingleContactInformation(int index);
	int		addContactField(std:: string& input, Contact &newContact,
				const std:: string& field, void (Contact:: *setter)(std::string&));

public:
	int		Count;
	//Constructor
	PhoneBook() : mIndex(0), Count(0) {} 
	
	//Methods (public)
	int		addContact();
    void	searchContact();
};

#endif