/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:22:41 by erian             #+#    #+#             */
/*   Updated: 2025/02/22 11:27:09 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cout << DARK_BLUE << "fragtrap " << name << " created" << NC << std::endl;
	_attack_damage = 30;
	_energy_points = 100;
	_hit_points = 100;
}

FragTrap::~FragTrap() {
	std::cout << RED << "fragtrap " << _name << " destroyed" << NC << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << DARK_YELLOW << _name << " requests a high five!" << NC << std::endl;
}