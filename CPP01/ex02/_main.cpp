/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:47:27 by erian             #+#    #+#             */
/*   Updated: 2025/02/02 12:06:32 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#define BLUE	"\e[38;5;123m"
#define NC      "\033[0m"

using std::cout;
using std::endl;

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string *strptr = &str;
	std::string &strref = str;
	
	cout << "\nmemory:\n"
	<< "original:  " << BLUE << &str << "\n" << NC
	<< "pointer:   " << BLUE << &strptr << "\n" << NC
	<< "reference: " << BLUE << &strref << "\n" << NC;

	cout << "\nvalue:\n"
	<< "original:  " << BLUE << str << "\n" << NC
	<< "pointer:   " << BLUE << *strptr << "\n" << NC
	<< "reference: " << BLUE << strref << "\n" << NC;

	return 0;
}
