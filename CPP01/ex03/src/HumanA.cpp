/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:12:27 by erian             #+#    #+#             */
/*   Updated: 2025/01/29 20:13:07 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}

void HumanA::attack()
{

	std::cout << DARKBLUE << _name << BLUE << " attacks with their "
			<< YELLOW << _weapon.getType() << NC << "\n";
}

void HumanA::setWeapon(Weapon weapon) { 
	_weapon = weapon;
}

Weapon HumanA::getWeapon() {
	return _weapon;
}

HumanA::~HumanA() {}
