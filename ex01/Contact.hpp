/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:21:36 by mmeier            #+#    #+#             */
/*   Updated: 2024/11/21 15:23:24 by mmeier           ###   ########.fr       */
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



// public:
// 	//Constructor (parameterized)
// 	Contact(std::string first_name, std::string last_name, std::string nickname,
// 		std::string phone_no, std::string darkest_secret)
// 		//member initialization list
// 		: first_name(first_name), last_name(last_name), nickname(nickname),
// 			phone_no(phone_no), darkest_secret(darkest_secret){}
// 	//getters
// 	std::string	getFirstName() const { return first_name; }
//     std::string	getLastName() const { return last_name; }
//     std::string	getNickname() const { return nickname; }
//     std::string	getPhoneNo() const { return phone_no; }
//     std::string	getDarkestSecret() const { return darkest_secret; }
// 	//setters
// 	void	setFirstName(const std::string& name) { first_name = name;}
// 	void	setLastName(const std::string& name) { last_name = name;}
// 	void	setNickname(const std::string& name) { nickname = name;}
// 	void	setPhoneNo(const std::string& name) { phone_no = name;}
// 	void	setDarkestSecret(const std::string& name) { darkest_secret = name;}
// };