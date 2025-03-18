/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:59:46 by erian             #+#    #+#             */
/*   Updated: 2025/03/17 17:25:09 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : 
AForm(other.getName(), other.getSignGrade(), other.getExecGrade()), _target(other.getTarget()) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& original)
{
	_target = original._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getTarget() const { 
    return _target;
}

void PresidentialPardonForm::action() const {
    std::cout << YELLOW << _target << " has been pardoned by Zaphod Beeblebrox\n" << NC;
}