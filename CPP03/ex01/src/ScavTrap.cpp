/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:22:41 by erian             #+#    #+#             */
/*   Updated: 2025/02/22 11:17:21 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	std::cout << DARK_ORANGE << "scavtrap " << name << " created" << NC << std::endl;
	_attack_damage = 20;
	_energy_points = 50;
	_hit_points = 100;
}

ScavTrap::~ScavTrap() {
	std::cout << RED << "scavtrap " << _name << " destroyed" << NC << std::endl;
}

void ScavTrap::attack(std::string const &target) {
	std::cout << DARK_RED << "scavtrap " << _name << " attacks " << target << " causing " << _attack_damage << " points of damage!" << NC << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << DARK_BLUE << _name << " has entered Gate keeper mode" << NC << std::endl;
}