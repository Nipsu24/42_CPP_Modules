/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:05:06 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/23 11:48:31 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// void	PhoneBook::printErrorEmptyField(const std::string& field)
// {
// 	std::cout << "Field <" << field << "> cannot be left empty\n";
// }

// /*Takes input string and returns 1 in case phone number is not valid.
//   Not valid phone number is defined as follows: contains any characters
//   except optional '+' on 0 index, a single space between digits, digits.*/
// int	PhoneBook:: checkForValidNumber(std::string input)
// {
// 	for(size_t i = 0; i < input.length(); i++)
// 	{
// 		if(input[0] == '+' || isspace(input[i]))
// 			i++;
// 		if(input[i] && !isdigit(input[i]))
// 			return (1);
// 	}
// 	return (0);
// }

// /* *setter declares member function pointer (no parameter name after string& required)*/
// void	PhoneBook::addContactField(std::string& input, Contact &newContact,
// 					const std::string& field, void (Contact:: *setter)(std::string&))
// {
// 	while (input.empty())
// 	{
// 		std::cout << "Enter " << field << ": ";
// 		std::getline(std::cin, input);
		
// 		if (input.empty())
// 			printErrorEmptyField(field);
// 		if (field == "phone number")
// 		{
// 			if (checkForValidNumber(input))
// 			{
// 				std::cout << "Error. Invalid phone number.\n";
// 				input.clear();
// 			}
// 		}
// 		(newContact.*setter)(input);
// 	}
// 	input.clear();
// }

// void	PhoneBook::addContact()
// {
// 	Contact	newContact;
// 	std::string	input;
	
// 	addContactField(input, newContact, "first name", &Contact::setFirstName);
// 	addContactField(input, newContact, "last name", &Contact::setLastName);
// 	addContactField(input, newContact, "nickname", &Contact::setNickname);
// 	addContactField(input, newContact, "phone number", &Contact::setPhoneNo);
// 	addContactField(input, newContact, "darkest secret", &Contact::setDarkestSecret);
// 	if (mIndex >= 8)
// 	{
// 		mIndex = 0;
// 		mContacts[mIndex] = newContact;
// 	}
// 	else
// 		mContacts[mIndex] = newContact;
// 	mIndex = mIndex + 1;
	
	// std::cout << "\nCurrent contacts in the PhoneBook:\n";
    // for (int i = 0; i < mIndex; i++) {
    //     std::cout << "Contact " << i + 1 << ":\n";
    //     std::cout << "First Name: " << mContacts[i].getFirstName() << std::endl;
    //     std::cout << "Last Name: " << mContacts[i].getLastName() << std::endl;
    //     std::cout << "Nickname: " << mContacts[i].getNickname() << std::endl;
    //     std::cout << "Phone Number: " << mContacts[i].getPhoneNo() << std::endl;
    //     std::cout << "Darkest Secret: " << mContacts[i].getDarkestSecret() << std::endl;
    //     std::cout << "-------------------------------\n";
    // }
// }

void	PhoneBook::printTableHeader()
{
	std::cout << std::right << std::setw(10) << "Index" << "|";
	std::cout << std::right << std::setw(10) << "First Name" << "|";
	std::cout << std::right << std::setw(10) << "Last Name" << "|";
	std::cout << std::right << std::setw(10) << "Nickname" << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::printAllContacts()
{
	for (int i = 0; i < mIndex; i++)
	{
		std::cout << std::right << std::setw(10) << i + 1 << "|";
		if (mContacts[i].getFirstName().length() > 10)
			std::cout << mContacts[i].getFirstName().substr(0, 9) << "." << "|";
		else
			std::cout << std::right << std::setw(10) << mContacts[i].getFirstName() << "|";
		if (mContacts[i].getLastName().length() > 10)
			std::cout << mContacts[i].getLastName().substr(0, 9) << "." << "|";
		else
			std::cout << std::right << std::setw(10) << mContacts[i].getLastName() << "|";
		if (mContacts[i].getNickname().length() > 10)
			std::cout << mContacts[i].getNickname().substr(0, 9) << "." << std::endl;
		else
			std::cout << std::right << std::setw(10) << mContacts[i].getNickname() << std::endl;
	}
	std::cout << std::endl;
}

void	PhoneBook::printSingleContactInformation(int index)
{
	std::cout << "***********Details of contact " << index + 1 << "**********\n";
	std::cout << mContacts[index].getFirstName() << std::endl;
	std::cout << mContacts[index].getLastName() << std::endl;
	std::cout << mContacts[index].getNickname() << std::endl;
	std::cout << mContacts[index].getPhoneNo() << std::endl;
	std::cout << mContacts[index].getDarkestSecret() << std::endl;
	std::cout << "*****************************************\n";
	std::cout << "PhoneBook Options (Enter either of them):\n";
	std::cout << "ADD\n";
	std::cout << "SEARCH\n";
	std::cout << "EXIT\n";
	std::cout << "*****************************************\n";
}

void	PhoneBook::printContactDetails()
{
	std::string	input;
	bool		indexExists = false;
	
	while (!indexExists)
	{
		std::cout << "Enter respective index for further contact details.\n";
		std::getline(std::cin, input);
		try
		{
			int	enteredIndex = stoi(input);
			for (int j = 0; j < mIndex; j++)
			{
				if (enteredIndex == j + 1)
				{
					printSingleContactInformation(enteredIndex - 1);
					indexExists = true;
					break ;
				}
			}
			if (!indexExists)
				std::cout << "The index you entered could not be found. Please try again.\n";
		}
		catch (std::invalid_argument &e){
			std::cout << "Invalid input. Please enter a number.\n";
		}
		catch (std::out_of_range &e){
			std::cout << "Input number is out of range. Please try again.\n";
		}
	}
}

void	PhoneBook::searchContact()
{
	printTableHeader();
	printAllContacts();
	printContactDetails();
}
