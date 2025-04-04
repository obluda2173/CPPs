/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:59:30 by erian             #+#    #+#             */
/*   Updated: 2025/03/24 12:29:23 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->exchangeRates = other.exchangeRates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadExchangeRates(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << ERROR << "Error: could not open file." << NC << std::endl;
		return false;
	}
	std::string line, date;
	double rate;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::istringstream ss(line);
		if (std::getline(ss, date, ',') && (ss >> rate)) {
			exchangeRates[date] = rate;
		}
	}
	file.close();
	return true;
}

void BitcoinExchange::processInputFile(const std::string& filename) const {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << ERROR << "Error: could not open file." << NC << std::endl;
		return;
	}
	std::string line, date, valueStr;
	double value;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::getline(ss, date, '|');
		std::getline(ss, valueStr);
		date = trim(date);
		valueStr = trim(valueStr);

		if (!isValidDate(date)) {
			std::cerr << ERROR << "Error: bad input => " << line << NC << std::endl;
			continue;
		}

		if (!isValidValue(valueStr)) {
			continue;
		}

		value = std::atof(valueStr.c_str());
		std::string closestDate = getClosestDate(date);
		if (closestDate.empty()) {
			std::cerr << ERROR << "Error: no available rate for date." << NC << std::endl;
			continue;
		}

		std::cout << date << " => " << value << " = " << value * exchangeRates.find(closestDate)->second << std::endl;
	}
	file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}

	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);

	if (!std::isdigit(yearStr[0]) || !std::isdigit(yearStr[1]) || 
		!std::isdigit(yearStr[2]) || !std::isdigit(yearStr[3]) ||
		!std::isdigit(monthStr[0]) || !std::isdigit(monthStr[1]) ||
		!std::isdigit(dayStr[0]) || !std::isdigit(dayStr[1])) {
		return false;
	}

	int year = std::atoi(yearStr.c_str());
	int month = std::atoi(monthStr.c_str());
	int day = std::atoi(dayStr.c_str());

	return (year >= 2009 && year <= 2025) && (month >= 1 && month <= 12) && (day >= 1 && day <= 31);
}

bool BitcoinExchange::isValidValue(const std::string& value) const {
	for (size_t i = 0; i < value.size(); i++) {
		if ((value[i] < '0' || value[i] > '9') && value[i] != '.') {
			std::cerr << ERROR << "Error: not a positive number." << NC << std::endl;
			return false;
		}
	}
	float float_value = std::atof(value.c_str());
	if (float_value < 0.0 || float_value > 1000.0) {
		std::cerr << ERROR << "Error: too large number." << NC << std::endl;
		return false;
	}
	return true;
}

std::string BitcoinExchange::trim(const std::string& str) const {
	size_t first = str.find_first_not_of(" ");
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(" ");
	return str.substr(first, (last - first + 1));
}

std::string BitcoinExchange::getClosestDate(const std::string& date) const {
	std::map<std::string, double>::const_iterator it = exchangeRates.lower_bound(date);

	if (it != exchangeRates.end() && it->first == date) {
		return it->first;
	}

	if (it == exchangeRates.begin()) {
		return "";
	}

	return (--it)->first;
}