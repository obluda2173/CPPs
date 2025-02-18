/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:08:29 by erian             #+#    #+#             */
/*   Updated: 2025/02/17 17:08:07 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main() {

	PhoneBook phone_book;
	std::string input;

	std::cout << "available commands: " << BLUE << "[ADD] [SEARCH] [EXIT]" << NC << std::endl;
	while (true) {
		std::cout << "\nenter your command: ";
		if (!std::getline(std::cin, input, '\n'))
			break;
		if (input == "ADD")
			phone_book.Add();
		else if (input == "SEARCH")
			phone_book.Search();
		else if (input == "EXIT")
			break;
		else
			std::cout << RED << "unrecognised command" << NC << std::endl;
	}
	return 0;

}