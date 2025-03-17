/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:59:46 by erian             #+#    #+#             */
/*   Updated: 2025/03/17 16:16:22 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : 
AForm(other.getName(), other.getSignGrade(), other.getExecGrade()), _target(other.getTarget()) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& original)
{
	_target = original._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const {
    return _target;
}

void ShrubberyCreationForm::action() const {
	std::ofstream file;
	// file.open(_target + "_shrubbery");
	file.open((_target + "_shrubbery").c_str());
	file << "888                           \n"
		<< "888                           \n"
		<< "888                           \n"
		<< "888888888d888 .d88b.  .d88b.  \n"
		<< "888   888P\"  d8P  Y8bd8P  Y8b\n"
		<< "888   888    8888888888888888 \n"
		<< "Y88b. 888    Y8b.    Y8b.     \n"
		<< "\"Y888888     \"Y8888  \"Y8888";

	file.close();	
}