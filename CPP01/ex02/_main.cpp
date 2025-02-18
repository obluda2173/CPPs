/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:47:27 by erian             #+#    #+#             */
/*   Updated: 2025/02/18 12:22:20 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#define BLUE	"\e[38;5;123m"
#define NC		"\033[0m"

int main() {
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;
	
	std::cout
	<< "\nmemory:\n"
	<< "original:  " << BLUE << &string << "\n" << NC
	<< "pointer:   " << BLUE << &stringPTR << "\n" << NC
	<< "reference: " << BLUE << &stringREF << "\n" << NC
	<< "\nvalue:\n"
	<< "original:  " << BLUE << string << "\n" << NC
	<< "pointer:   " << BLUE << *stringPTR << "\n" << NC
	<< "reference: " << BLUE << stringREF << "\n" << NC << std::endl;

	return 0;
}