/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:28:09 by erian             #+#    #+#             */
/*   Updated: 2025/02/17 17:13:40 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contact_index(0) {}

void PhoneBook::Add() {

	Contact new_contact;

	new_contact.first_name = GetField("first name: ");
	new_contact.last_name = GetField("last name: ");
	new_contact.nickname = GetField("nickname: ");
	new_contact.phone_number = GetField("phone number: ");
	new_contact.darkest_secret = GetField("darkest secret: ");

	std::cout << GREEN << "contact added" << NC << std::endl;

	_contact_list[_contact_index % 8] = new_contact;
	_contact_index++;

}

void PhoneBook::Search() {

	if (_contact_index == 0) {
		std::cout << RED << "contact list is empty." << NC << std::endl;
		return;
	}

	DisplayHeader();
	DisplayContactList();

	int index = GetContactIndex("index of contact to display: ");
	if (index == -1) return; 

	Show(index);

}

void PhoneBook::DisplayHeader() const {

	std::cout << "____________________________________________\n"
		<< "|" << MAGENTA << "  index   " << NC
		<< "|" << MAGENTA << "first name" << NC
		<< "|" << MAGENTA << "last  name" << NC
		<< "|" << MAGENTA << " nickname " << NC
		<< "|\n";

}

void PhoneBook::DisplayContactList() const {

	int i = 0;

	while (i < 8 && _contact_list[i].first_name != "") {
		std::cout << "|" << DARK_BLUE << std::setw(10) << i << NC
				<< "|" << BLUE << std::setw(10) << ShortStr(_contact_list[i].first_name) << NC
				<< "|" << BLUE << std::setw(10) << ShortStr(_contact_list[i].last_name) << NC
				<< "|" << BLUE << std::setw(10) << ShortStr(_contact_list[i].nickname) << NC
				<< "|\n";
		i++;
	}
	std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;

}

int PhoneBook::GetContactIndex(const std::string &prompt) const {

	std::string input = GetField(prompt);
	std::stringstream ss(input);
	int index;

	if (!(ss >> index) || !(ss.eof()) || index < 0 || index >= _contact_index) {
		std::cout << RED << "invalid index\n" << NC;
		return -1;
	}

	return index;

}

void PhoneBook::Show(int index) const {

	const Contact& contact = _contact_list[index];
	std::cout << DARK_BLUE << "first name: " << BLUE << contact.first_name << "\n"
			<< DARK_BLUE << "last name: " << BLUE << contact.last_name << "\n"
			<< DARK_BLUE << "nickname: " << BLUE << contact.nickname << "\n"
			<< DARK_BLUE << "phone number: " << BLUE << contact.phone_number << "\n"
			<< DARK_BLUE << "darkest secret: " << BLUE << contact.darkest_secret << NC << std::endl;

}

std::string PhoneBook::ShortStr(const std::string &str) const {
	return (str.length() > 10) ? str.substr(0, 9) + "." : str;
}

std::string PhoneBook::GetField(const std::string &prompt) const {

	std::string input;

	std::cout << DARK_BLUE << prompt << NC;
	std::getline(std::cin, input, '\n');

	return input;

}

PhoneBook::~PhoneBook() {}