/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:28:09 by erian             #+#    #+#             */
/*   Updated: 2025/01/20 11:12:34 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contact_index(0) {}

void PhoneBook::Add() {
	Contact new_contact;
	
	new_contact.first_name = GetField("fisrt name: ");
	new_contact.last_name = GetField("last name: ");
	new_contact.nickname = GetField("nickname: ");
	new_contact.phone_number = GetField("phone number: ");
	new_contact.darkest_secret = GetField("darkest secret: ");

	std::cout << BLUE << "-{contact added}-\n" << NC;
	
	_contact_list[_contact_index % 8] = new_contact;
	_contact_index++;
}

void PhoneBook::DisplayHeader() {
	std::cout << std::endl;
	std::cout << "____________________________________________"
		<< std::endl
		<< "|" << MAGENTA << "  index   " << NC
		<< "|" << MAGENTA << "first name" << NC
		<< "|" << MAGENTA << "last  name" << NC
		<< "|" << MAGENTA << " nickname " << NC
		<< "|" << std::endl;
}

void PhoneBook::Search() {
	int i = 0;
	int display_contact;

	if (_contact_index == 0) {
		std::cout << RED << "contact list is empty\n" << NC;
		return;
	}

	DisplayHeader();
	
	while (i < 8 && _contact_list[i].first_name != "") {
		std::cout << "|" << DARKBLUE << std::setw(10) << i << NC
			<< "|" << BLUE << std::setw(10) << ShortStr(_contact_list[i].first_name) << NC
			<< "|" << BLUE << std::setw(10) << ShortStr(_contact_list[i].last_name) << NC
			<< "|" << BLUE << std::setw(10) << ShortStr(_contact_list[i].nickname) << NC
			<< "|" << std::endl;
		i++;
	}
	std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n";
	
	try {
		display_contact = std::stoi(GetField("index of contact to display: "));
	} catch(...) {
		std::cout << RED << "invalid index\n" << NC;
		return;
	}
	
	Show(display_contact);
}

void PhoneBook::Show(int index) {
	if (index < 0 || (index + 1) > _contact_index) {
		std::cout << RED << "invalid index\n" << NC;
		return;
	}
	std::cout
	<< DARKBLUE << "first name: "
	<< BLUE << _contact_list[index].first_name << std::endl
	<< DARKBLUE << "last name: "
	<< BLUE << _contact_list[index].last_name  << std::endl
	<< DARKBLUE << "nickname: "
	<< BLUE << _contact_list[index].nickname << std::endl
	<< DARKBLUE << "phone number: "
	<< BLUE << _contact_list[index].phone_number << std::endl
	<< DARKBLUE << "darkest secret: "
	<< BLUE << _contact_list[index].darkest_secret << NC << std::endl << std::endl;
}

std::string PhoneBook::ShortStr(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 7) + "...";
	return str;
}

std::string PhoneBook::GetField(std::string prompt) {
	std::string input = "";
	
	do {
		std::cout << DARKBLUE << prompt << NC;
		getline(std::cin, input, '\n');
	}
	while (input == "");

	return (input);
}

PhoneBook::~PhoneBook() {}