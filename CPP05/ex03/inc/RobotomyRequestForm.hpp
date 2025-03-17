/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:21:25 by erian             #+#    #+#             */
/*   Updated: 2025/03/17 16:07:04 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <time.h>
#include <cstdlib>
#include <fstream>

#include "_Colors.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		// attributes
		std::string _target;

	public:
		// OCN
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		// geters n setters
		std::string getTarget() const;

		// methods
		void action() const;
};