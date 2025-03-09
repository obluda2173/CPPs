/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:24:03 by erian             #+#    #+#             */
/*   Updated: 2025/03/09 15:00:38 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 150);
		Bureaucrat b3("b3", 150);
		Bureaucrat b4("b4", 2);
		Bureaucrat b5("b5", 149);

		std::cout << DARK_RED << b1 << NC << GREEN << " will be incremented"  "\n";
		std::cout << DARK_ORANGE << b2 << NC << RED << " will be decremented"  "\n";
		std::cout << DARK_YELLOW << b3 << NC << GREEN << " will be incremented"  "\n";
		std::cout << DARK_GREEN << b4 << NC << RED << " will be decremented"  "\n";
		std::cout << DARK_BLUE << b5 << NC << GREEN << " will be incremented"  "\n";

		try {
			b1.incrementGrade();
		} catch (std::exception &e) {
			std::cout << ERROR << e.what() << NC << "\n";
		}

		try {
			b2.decrementGrade();
		} catch (std::exception &e) {
			std::cout << ERROR << e.what() << NC << "\n";
		}

		try {
			b3.incrementGrade();
		} catch (std::exception &e) {
			std::cout << ERROR << e.what() << NC << "\n";
		}

		try {
			b4.decrementGrade();
		} catch (std::exception &e) {
			std::cout << ERROR << e.what() << NC << "\n";
		}

		try {
			b5.incrementGrade();
		} catch (std::exception &e) {
			std::cout << ERROR << e.what() << NC << std::endl;
		}

		std::cout << DARK_RED << b1 << NC << "\n";
		std::cout << DARK_ORANGE << b2 << NC << "\n";
		std::cout << DARK_YELLOW << b3 << NC << "\n";
		std::cout << DARK_GREEN << b4 << NC << "\n";
		std::cout << DARK_BLUE << b5 << NC << "\n";

	} catch (std::exception &e) {
		std::cerr << ERROR << "Failed to create Bureaucrat: " << e.what() << NC << std::endl;
	}

	return 0;
}