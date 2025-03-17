/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:24:03 by erian             #+#    #+#             */
/*   Updated: 2025/03/17 17:22:53 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	Bureaucrat Erik("Mr. Erik An", 1);
	Bureaucrat pleb("some pleb", 150);
	PresidentialPardonForm presidental_form("some pleb");
	RobotomyRequestForm robotomy_form("some pleb");
	ShrubberyCreationForm shrubbery_form("somewhere_in_spain");

	pleb.signForm(presidental_form);
	Erik.signForm(presidental_form);
	pleb.executeForm(presidental_form);
	Erik.executeForm(presidental_form);

	pleb.signForm(robotomy_form);
	Erik.signForm(robotomy_form);
	pleb.executeForm(robotomy_form);
	Erik.executeForm(robotomy_form);

	pleb.signForm(shrubbery_form);
	Erik.signForm(shrubbery_form);
	pleb.executeForm(shrubbery_form);
	Erik.executeForm(shrubbery_form);
	
	return 0;
}

/*
 * what to test:
 * sign and execute shrubbery
 * sign and execute robotomy
 * sign and execute president
 * create a pleb who can not sign or execute anything
 */