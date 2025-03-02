/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeier <mmeier@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:04:52 by mmeier            #+#    #+#             */
/*   Updated: 2025/03/02 13:10:33 by mmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>

class BitcoinExchange {
	private:
	std::map<std::string, float> mMap;
	
	public:
		//constructors
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		//methods
		void	calculateBitcoinExchangeRate(const std::string inputFile);
		bool	storeBitcoinDataInMap();
		void	compareDataWithInput(const std::string inputBuffer);
		bool	validateInputFormat(std::string& inputBuffer);
		bool	validateDateFormat(std::string& inputBuffer);
		bool	validateSeparatorAndNumberFormat(std::string& inputBuffer);
		bool	validateInputContent(std::string& inputBuffer);
		bool	validateDateContent(std::string& inputBuffer);
		bool	validateNumberContent(std::string& inputBuffer);
};

#endif