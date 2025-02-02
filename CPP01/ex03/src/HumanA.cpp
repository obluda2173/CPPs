/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:12:27 by erian             #+#    #+#             */
/*   Updated: 2025/02/02 12:06:55 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

using std::cout;
using std::endl;

HumanA::HumanA(const std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}

void HumanA::attack()
{
	cout << DARKBLUE << _name << BLUE << " attacks with their "
			<< YELLOW << _weapon.getType() << NC << "\n";
}

void HumanA::setWeapon(Weapon weapon) { _weapon = weapon; }

Weapon HumanA::getWeapon() { return _weapon; }

HumanA::~HumanA() {}
