/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:08:36 by erian             #+#    #+#             */
/*   Updated: 2025/01/20 07:05:49 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <exception>

#include "Contact.hpp"
#include "Colors.hpp"

class PhoneBook {
	private:
		int			_contact_index;
		Contact		_contact_list[8];
		std::string	GetField(std::string prompt);
	public:
		PhoneBook(void);
		~PhoneBook(void);

		bool	exit;
		void		Add(void);
		void		Search(void);
		void		DisplayHeader();
		std::string	ShortStr(std::string str);
		void		Show(int index);
};