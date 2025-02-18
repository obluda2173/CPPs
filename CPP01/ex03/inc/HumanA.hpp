/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:51:04 by erian             #+#    #+#             */
/*   Updated: 2025/02/18 13:56:51 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanA {
	private:
		std::string _name;
		Weapon &_weapon;

	public:
		HumanA( const std::string name, Weapon &weapon );

		void attack();

		~HumanA();
	};