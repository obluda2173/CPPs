/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:59:46 by erian             #+#    #+#             */
/*   Updated: 2025/03/17 15:48:56 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : 
AForm(other.getName(), other.getSignGrade(), other.getExecGrade()), _target(other.getTarget()) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& original)
{
	_target = original._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() const {
    return _target;
}

void RobotomyRequestForm::action() const {
	srand(time(0));
	if (rand() % 2)
		std::cout << BLUE << _target << " has been robotomized successfully\n" << NC;
	else
		std::cout << ORANGE << _target << " has failed\n" << NC;
}