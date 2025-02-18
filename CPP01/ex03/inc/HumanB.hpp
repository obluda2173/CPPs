/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:51:02 by erian             #+#    #+#             */
/*   Updated: 2025/02/18 13:57:07 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanB {
	private:
		std::string _name;
		Weapon *_weapon;

	public:
		HumanB( const std::string name );
		HumanB( const std::string name, Weapon &weapon );

		void attack();
		void setWeapon( Weapon &weapon );

		~HumanB();
};
