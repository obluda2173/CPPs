/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:24:03 by erian             #+#    #+#             */
/*   Updated: 2025/03/18 14:51:25 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	Bureaucrat Erik("Mr. Erik An", 1);
	Bureaucrat Pisciner("Pisciner", 150);
	PresidentialPardonForm presidental_form("Pisciner");
	RobotomyRequestForm robotomy_form("Pisciner");
	ShrubberyCreationForm shrubbery_form("somewhere_in_spain");

	Pisciner.signForm(presidental_form);
	Erik.signForm(presidental_form);
	Pisciner.executeForm(presidental_form);
	Erik.executeForm(presidental_form);

	Pisciner.signForm(robotomy_form);
	Erik.signForm(robotomy_form);
	Pisciner.executeForm(robotomy_form);
	Erik.executeForm(robotomy_form);

	Pisciner.signForm(shrubbery_form);
	Erik.signForm(shrubbery_form);
	Pisciner.executeForm(shrubbery_form);
	Erik.executeForm(shrubbery_form);

	return 0;
}