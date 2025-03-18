/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:24:03 by erian             #+#    #+#             */
/*   Updated: 2025/03/18 14:47:55 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>

#include "unistd.h"
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define MAGGOTS_COUNT 11

int main() {
	std::srand(std::time(0));
	Bureaucrat *eu_directive_maggots[MAGGOTS_COUNT];
	Form *eu_bottle_cap_proposal_form[MAGGOTS_COUNT];
	unsigned int count = 0;

	std::cout << GREEN << "the new bottle cap design voting began!\n" << NC;

	for (int i = 0; i < MAGGOTS_COUNT; i++) {
		try {
			eu_directive_maggots[i] = new Bureaucrat("random maggot", rand() % 120 + 1);
			std::cout << DARK_BLUE << *eu_directive_maggots[i] << NC << "\n";
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			eu_bottle_cap_proposal_form[i] = new Form("random form", (rand() % 150 + 1), (rand() % 150 + 1));
			std::cout << DARK_YELLOW << *eu_bottle_cap_proposal_form[i] << NC << "\n";
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		usleep(100000);
	}

	for (int i = 0; i < MAGGOTS_COUNT; i++) {
		try {
			eu_directive_maggots[i]->signForm(*eu_bottle_cap_proposal_form[i]);
			std::cout << *eu_bottle_cap_proposal_form[i] << "\n";
			if (eu_bottle_cap_proposal_form[i]->isSigned())
				count++;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		usleep(100000);
	}
	
	std::cout << GREEN << static_cast<unsigned>((static_cast<double>(count) / MAGGOTS_COUNT) * 100) << "% of the EU Directive maggots voted for redesigning bottle cups\n" << NC;

	if (count > MAGGOTS_COUNT / 2)
		std::cout << GREEN << "congratulations, now you suffer from bottle cups!" << NC << std::endl;
	else
		std::cout << RED << "EU directive decided to repeat the voting, please run the program again." << NC << std::endl;

	for (int i = 0; i < MAGGOTS_COUNT; i++) {
		delete eu_directive_maggots[i];
		delete eu_bottle_cap_proposal_form[i];
	}

	return 0;
}