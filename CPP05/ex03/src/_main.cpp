/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:24:03 by erian             #+#    #+#             */
/*   Updated: 2025/03/18 13:19:08 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define MASSIVE_WORKLOAD 42

int main() {
	Intern eighteenYoIntern;
	AForm *currentForm;
	std::string formNames[4] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation", "NonExistingForm"};
	std::string targetNames[4] = {"Kanye West", "Mark Zuckerberg", "Immermannhoff 1", "NonExistingTarget"};
	
	for (int i = 0; i < MASSIVE_WORKLOAD; i++) {
		currentForm = eighteenYoIntern.makeForm(formNames[i % 4], targetNames[i % 4]);
		if (currentForm) {
			(*currentForm).action();
			delete currentForm;
		}
		usleep(200000);
	}
	return 0;
}