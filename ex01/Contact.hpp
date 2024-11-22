/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:21:36 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/22 16:35:57 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <cctype>
#include <string>

class Contact {
private:
	std::string mFirstName;
	std::string mLastName;
	std::string mNickname;
	std::string mPhoneNo;
	std::string mDarkestSecret;

public:
	//Default constructor
	Contact() = default;
	//getters
	std::string	getFirstName() const;
    std::string	getLastName() const;
    std::string	getNickname() const;
    std::string	getPhoneNo() const;
    std::string	getDarkestSecret() const;
	//setters
	void	setFirstName(const std::string& name);
	void	setLastName(const std::string& name);
	void	setNickname(const std::string& name);
	void	setPhoneNo(const std::string& number);
	void	setDarkestSecret(const std::string& secret);
};

#endif
