/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:24:03 by erian             #+#    #+#             */
/*   Updated: 2025/03/09 17:29:39 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include <ctime>
#include <cstdlib>

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define MAGGOTS_COUNT 11

int main() {
	std::srand(std::time(0));
	Bureaucrat *eu_maggots[MAGGOTS_COUNT];
	Form *eu_bottle_cap_proposal_form[MAGGOTS_COUNT];
	unsigned int count = 0;

	for (int i = 0; i < MAGGOTS_COUNT; i++) {
		try {
			eu_maggots[i] = new Bureaucrat("random maggot", rand() % 100 + 1);
			std::cout << DARK_BLUE << *eu_maggots[i] << NC << "\n";
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
			eu_maggots[i]->signForm(*eu_bottle_cap_proposal_form[i]);
			if (eu_bottle_cap_proposal_form[i]->isSigned())
				count++;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		usleep(100000);
	}
	
	std::cout << static_cast<unsigned>((static_cast<double>(count) / MAGGOTS_COUNT) * 100) << "% of the maggots voted for bottle cups proposal" << std::endl;

	if (count > MAGGOTS_COUNT / 2)
		std::cout << GREEN << "congratulations, now you suffer from bottle cups!!!" << NC << std::endl;
	else
		std::cout << RED << "you are safe from bottle cup, for now..." << NC << std::endl;

	for (int i = 0; i < MAGGOTS_COUNT; i++) {
		delete eu_maggots[i];
		delete eu_bottle_cap_proposal_form[i];
	}

	return 0;
}