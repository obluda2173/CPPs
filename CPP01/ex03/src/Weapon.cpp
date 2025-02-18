/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:12:32 by erian             #+#    #+#             */
/*   Updated: 2025/02/18 13:27:04 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( const std::string type ) : _type(type) {}

const std::string Weapon::getType() {
	return (_type);
}

void Weapon::setType( const std::string type ) {
	_type = type;
}

Weapon::~Weapon() {}