/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:28:09 by erian             #+#    #+#             */
/*   Updated: 2025/02/01 11:57:15 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

using std::cout;
using std::endl;

PhoneBook::PhoneBook() : _contact_index(0) {}

void PhoneBook::Add() {
	Contact new_contact;

	new_contact.first_name = GetField("First name: ");
	new_contact.last_name = GetField("Last name: ");
	new_contact.nickname = GetField("Nickname: ");
	new_contact.phone_number = GetField("Phone number: ");
	new_contact.darkest_secret = GetField("Darkest secret: ");

	cout << BLUE << "-{ Contact added }-" << NC << endl;

	_contact_list[_contact_index % 8] = new_contact;
	_contact_index++;
}

void PhoneBook::DisplayHeader() const {
    cout << endl
         << "____________________________________________" << endl
         << "|" << MAGENTA << "  index   " << NC
         << "|" << MAGENTA << " first name " << NC
         << "|" << MAGENTA << " last name " << NC
         << "|" << MAGENTA << " nickname " << NC
         << "|" << endl;
}

void PhoneBook::Search() {
    if (_contact_index == 0) {
        cout << RED << "Contact list is empty.\n" << NC;
        return;
    }

    DisplayHeader();
    DisplayContactList();

    int display_contact = GetContactIndex("Index of contact to display: ");
    if (display_contact == -1) return; // Invalid index or input

    Show(display_contact);
}

void PhoneBook::DisplayContactList() const {
    int i = 0;
    while (i < 8 && _contact_list[i].first_name != "") {
        cout << "|" << DARKBLUE << std::setw(10) << i << NC
             << "|" << BLUE << std::setw(10) << ShortStr(_contact_list[i].first_name) << NC
             << "|" << BLUE << std::setw(10) << ShortStr(_contact_list[i].last_name) << NC
             << "|" << BLUE << std::setw(10) << ShortStr(_contact_list[i].nickname) << NC
             << "|" << endl;
        i++;
    }
    cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n";
}

int PhoneBook::GetContactIndex(const std::string &prompt) const {
    std::string input = GetField(prompt);
    std::stringstream ss(input);
    int display_contact;

    if (!(ss >> display_contact) || !(ss.eof()) || display_contact < 0 || display_contact >= _contact_index) {
        cout << RED << "Invalid index\n" << NC;
        return -1;
    }
    return display_contact;
}

void PhoneBook::Show(int index) const {
    if (index < 0 || index >= _contact_index) {
        cout << RED << "Invalid index\n" << NC;
        return;
    }

    const Contact& contact = _contact_list[index];
    cout << DARKBLUE << "First name: " << BLUE << contact.first_name << endl
         << DARKBLUE << "Last name: " << BLUE << contact.last_name << endl
         << DARKBLUE << "Nickname: " << BLUE << contact.nickname << endl
         << DARKBLUE << "Phone number: " << BLUE << contact.phone_number << endl
         << DARKBLUE << "Darkest secret: " << BLUE << contact.darkest_secret << NC << endl;
}

std::string PhoneBook::ShortStr(const std::string &str) const {
    return (str.length() > 10) ? str.substr(0, 9) + "." : str;
}

std::string PhoneBook::GetField(const std::string &prompt) const {
    std::string input;
    do {
        cout << DARKBLUE << prompt << NC;
        getline(std::cin, input);
    } while (input.empty());
    return input;
}

PhoneBook::~PhoneBook() {}