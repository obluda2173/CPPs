/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:02:36 by erian             #+#    #+#             */
/*   Updated: 2025/03/18 12:19:13 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#include "_Colors.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		// OCN
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();
	
		// methods
		AForm *makeForm(std::string formName, std::string formTarget);
};