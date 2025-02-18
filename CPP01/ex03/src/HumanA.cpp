/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:12:27 by erian             #+#    #+#             */
/*   Updated: 2025/02/18 13:55:39 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( const std::string name, Weapon &weapon ) : _name(name), _weapon(weapon) {}

void HumanA::attack()
{
	std::cout
	<< DARK_BLUE << _name << NC << " attacks with their "
	<< DARK_ORANGE << _weapon.getType() << NC << std::endl;
}

HumanA::~HumanA() {}