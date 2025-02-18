/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:12:30 by erian             #+#    #+#             */
/*   Updated: 2025/02/18 13:57:43 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string name) : _name(name), _weapon(NULL) {}

void HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}

void HumanB::attack() {
	if (_weapon)
		std::cout
		<< DARK_BLUE << _name << NC << " attacks with their " 
		<< DARK_ORANGE<< _weapon->getType() << NC << std::endl;
	else
		std::cout << _name << " is not armed" << std::endl;
}

HumanB::~HumanB() {}