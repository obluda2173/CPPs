/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:59:16 by erian             #+#    #+#             */
/*   Updated: 2025/03/25 11:06:19 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>

#include "_Colors.hpp"

class BitcoinExchange {
	private:
		// attributes
		std::map<std::string, double> exchangeRates;
	
		// methods
		bool isValidDate(const std::string& date) const;
		bool isValidValue(const std::string& value) const;
		std::string trim(const std::string& str) const;
		std::string getClosestDate(const std::string& date) const;

	public:
		// OCF
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		// methods
		bool loadExchangeRates(const std::string& filename);
		void processInputFile(const std::string& filename) const;
};