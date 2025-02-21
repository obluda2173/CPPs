/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:22:41 by erian             #+#    #+#             */
/*   Updated: 2025/02/21 13:08:56 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	std::cout << DARK_MAGENTA << "scavtrap "<< name << " created" << std::endl;
	_attack_damage = 20;
	_energy_points = 50;
	_hit_points = 100;
}

ScavTrap::~ScavTrap() {
	std::cout << DARK_RED << "scavtrap " << _name << " destroyed" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << DARK_MAGENTA << _name << " has entered Gate keeper mode" << std::endl;
}