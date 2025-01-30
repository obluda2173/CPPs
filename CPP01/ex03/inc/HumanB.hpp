/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:51:02 by erian             #+#    #+#             */
/*   Updated: 2025/01/28 20:04:50 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Weapon.hpp"
#include "Colors.hpp"

class HumanB {
	private:
		std::string	_name;
		Weapon		*_weapon;
	public:
		HumanB(const std::string name);
		~HumanB();

		void	attack();
		void	setWeapon(Weapon &weapon);
		Weapon	getWeapon();
};
