/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:24:03 by erian             #+#    #+#             */
/*   Updated: 2025/03/20 13:52:02 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void printInt(const int &elem) {
	std::cout << elem << " ";
}

void printDouble(const double &elem) {
	std::cout << elem << " ";
}

void printString(const std::string &elem) {
	std::cout << elem << " ";
}

int main() {
	// array of integers
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);
	std::cout << RED << "Array of integers: ";
	iter(intArray, intArrayLength, printInt);
	std::cout << NC << std::endl;

	// array of doubles
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);
	std::cout << GREEN << "Array of doubles: ";
	iter(doubleArray, doubleArrayLength, printDouble);
	std::cout << NC << std::endl;

	// array of strings
	std::string stringArray[] = {"Hello", "World", "!"};
	size_t stringArrayLength = sizeof(stringArray) / sizeof(stringArray[0]);
	std::cout << BLUE << "Array of strings: ";
	iter(stringArray, stringArrayLength, printString);
	std::cout << NC << std::endl;

	return 0;
}