/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:08:36 by erian             #+#    #+#             */
/*   Updated: 2025/02/01 11:59:16 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <exception>
#include <sstream>

#include "Contact.hpp"
#include "Colors.hpp"

class PhoneBook {
    private:
        int _contact_index;
        Contact _contact_list[8]; 

        std::string GetField(const std::string &prompt) const;

    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void Add(void);
        void Search(void);
        void DisplayHeader(void) const;
        void DisplayContactList(void) const;
        void Show(int index) const;
        std::string ShortStr(const std::string &str) const;
        int GetContactIndex(const std::string &prompt) const;
};