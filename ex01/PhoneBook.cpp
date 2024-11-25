/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:05:06 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/25 11:45:58 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*Prints error message in case user tries to leave contact field empty.*/
void	PhoneBook::printErrorEmptyField(const std::string& field)
{
	std::cout << "Field <" << field << "> cannot be left empty\n";
}

/*Takes input string and returns 1 in case phone number is not valid.
  Not valid phone number is defined as follows: contains any characters
  except optional '+' on 0 index, a single space between digits, digits.*/
int	PhoneBook::checkForValidNumber(std::string input)
{
	for(size_t i = 0; i < input.length(); i++)
	{
		if(input[0] == '+' || isspace(input[i]))
			i++;
		if(input[i] && !isdigit(input[i]))
			return (1);
	}
	return (0);
}

/*Function contains loop for every contact field in order to populate it with user
  input. The '*setter' declares member function pointer (no parameter name after 
  string& required). Returns 1 in case user hits cntrl + D.*/
int	PhoneBook::addContactField(std::string& input, Contact &newContact,
					const std::string& field, void (Contact:: *setter)(std::string&))
{
	while (input.empty())
	{
		std::cout << "Enter " << field << ": ";
		if (!std::getline(std::cin, input))
			return (1);
		if (input.empty())
			printErrorEmptyField(field);
		if (field == "phone number")
		{
			if (checkForValidNumber(input))
			{
				std::cout << "Error. Invalid phone number.\n";
				input.clear();
			}
		}
		(newContact.*setter)(input);
	}
	input.clear();
	return (0);
}

/*Main function for adding contacts into the phonebook. Passes user input for each contact field
  including a pointer to the respective contact setter function to addContactsField function.
  Uses modulo calculation to account for cases where 9th contact is added (replaces oldest/first
  contact in the array). mCount variable is used in printAlContacts and printContactDetails in order
  to iterate through the existing contacts (stores actual number of contacts of the array).*/
int	PhoneBook::addContact()
{
	Contact	newContact;
	std::string	input;
	
	if (addContactField(input, newContact, "first name", &Contact::setFirstName)) return (1);
	if (addContactField(input, newContact, "last name", &Contact::setLastName)) return (1);
	if (addContactField(input, newContact, "nickname", &Contact::setNickname)) return (1);
	if (addContactField(input, newContact, "phone number", &Contact::setPhoneNo)) return (1);
	if (addContactField(input, newContact, "darkest secret", &Contact::setDarkestSecret)) return (1);
	mContacts[mIndex] = newContact;
	mIndex = (mIndex + 1) % 8;
	if (mCount < 8)
		mCount++;
	return (0);
}

/*Prints the header of the contacts list (prompted by user via "SEARCH")*/
void	PhoneBook::printTableHeader()
{
	std::cout << std::right << std::setw(10) << "Index" << "|";
	std::cout << std::right << std::setw(10) << "First Name" << "|";
	std::cout << std::right << std::setw(10) << "Last Name" << "|";
	std::cout << std::right << std::setw(10) << "Nickname" << std::endl;
	std::cout << std::endl;
}

/*Prints all existing contacts of the phonebook with the following fields:
  id, first name, last name, nickname on one line for each contact with a
  column width of 10 characters. In case the entry within a column exceeds
  column width, the entry gets abbrivated with a '.' on the 10th character. */
void	PhoneBook::printAllContacts()
{
	for (int i = 0; i < mCount; i++)
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

/*Prints contact information of a single contact, each field printed on an
  individual line. Afterwards the main menu of the phonebook is printed, showing
  the user the available options.*/
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

/*Prompts user to enter index of contact in order to display further details
  of this contact. Checks via try/catch and stoi function if input is a digit
  and existing in the phonebook. Displays error messages if stoi fails. Characters
  written after a correct index are discarded.*/
void	PhoneBook::printContactDetails()
{
	std::string	input;
	bool		indexExists = false;
	
	while (!indexExists)
	{
		std::cout << "Enter respective index for further contact details.\n";
		if (!std::getline(std::cin, input))
			break;
		try
		{
			int	enteredIndex = stoi(input);
			for (int j = 0; j < mCount; j++)
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
