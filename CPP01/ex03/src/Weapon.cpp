/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:12:32 by erian             #+#    #+#             */
/*   Updated: 2025/01/29 20:08:42 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string type) : _type(type) {}

const std::string Weapon::getType() { 
	return (_type); 
}

void Weapon::setType(const std::string type) { 
	_type = type; 
}

Weapon::~Weapon() {}
