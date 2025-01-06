/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:08:36 by erian             #+#    #+#             */
/*   Updated: 2025/01/06 17:52:58 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "Contact.hpp"
#include "Colors.hpp"

class PhoneBook
{
    private:
        Contact _contact_list[8];
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        bool    exit;
        void    add_contact(void);
        void    search_contact(void);
        
};