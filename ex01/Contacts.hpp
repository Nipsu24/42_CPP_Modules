/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:21:36 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/20 13:39:54 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#include <cctype>

class Contacts
{
private:
	/* data */
public:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_no;
	std::string darkest_secret;
	
	Contacts(/* args */);
	~Contacts();
};

Contacts::Contacts(/* args */)
{
}

Contacts::~Contacts()
{
}





#endif