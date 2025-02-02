/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:12:30 by erian             #+#    #+#             */
/*   Updated: 2025/02/02 15:28:31 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string name) : _name(name), _weapon(NULL) {}

void HumanB::attack()
{
	if (_weapon)
	{
		std::cout << DARKBLUE << _name << BLUE << " attacks with their "
			<< YELLOW << _weapon->getType() << NC << "\n";
	}
	else
		std::cout << DARKBLUE << _name << RED << " is not armed" << NC << "\n";
}

void HumanB::setWeapon(Weapon &weapon) { _weapon = &weapon; }

Weapon HumanB::getWeapon() { return *_weapon; }

HumanB::~HumanB() {}
