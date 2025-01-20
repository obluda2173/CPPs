/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:08:29 by erian             #+#    #+#             */
/*   Updated: 2025/01/20 07:21:08 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
// #include "Contact.hpp"
// #include "Colors.hpp"

int	main()
{
	PhoneBook	phone_book;
	std::string	input;

	std::cout <<"available commands: " << BLUE << "[ADD] [SEARCH] [EXIT]" << NC << std::endl;
	while (true)
	{
		std::cout << "enter your command: ";
		if (!std::getline(std::cin, input, '\n'))
			exit(1);
		if (input == "ADD")
			phone_book.Add();
		else if (input == "SEARCH")
			phone_book.Search();
		else if (input == "EXIT")
			break;
		else
			std::cout << RED << "unrecognised command\n" << NC;
	}
	return 0;
}
