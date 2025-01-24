/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:47:27 by erian             #+#    #+#             */
/*   Updated: 2025/01/24 10:38:28 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#define BLUE	"\e[38;5;123m"
#define NC		"\033[0m"


int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string *strptr = &str;
	std::string &strref = str;
	
	std::cout << "\nmemory:\n"
	<< "original:  " << BLUE << &str << "\n" << NC
	<< "pointer:   " << BLUE << &strptr << "\n" << NC
	<< "reference: " << BLUE << &strref << "\n" << NC;

	std::cout << "\nvalue:\n"
	<< "original:  " << BLUE << str << "\n" << NC
	<< "pointer:   " << BLUE << *strptr << "\n" << NC
	<< "reference: " << BLUE << strref << "\n" << NC;

	return 0;
}
