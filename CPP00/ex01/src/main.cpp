/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:08:29 by erian             #+#    #+#             */
/*   Updated: 2025/01/06 18:31:28 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phone_book;
	std::string	input;

	std::cout << DARKBLUE <<"Available commands: " << GREEN << "[ADD] [SEARCH] [EXIT]" << RESET << std::endl;
	while (!phone_book.exit)
	{
		std::cout << "Enter your command: " << std::endl;
		if (!std::getline(std::cin, input))
			exit(1);
		if (input.compare("EXIT"))
			phone_book.exit = true;
		else if (!input.compare("ADD"))
			phone_book.add_contact();
		else if (!input.compare("SEARCH"))
			phone_book.search_contact();
	}
	return 0;
}
