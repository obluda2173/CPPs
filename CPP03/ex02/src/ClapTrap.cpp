/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:22:41 by erian             #+#    #+#             */
/*   Updated: 2025/02/21 13:08:35 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << DARK_GREEN << "claptrap default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name) {
	std::cout << DARK_MAGENTA "claptrap " << name << " created" << std::endl;
	_attack_damage = 0;
	_energy_points = 10;
	_hit_points = 10;
}

ClapTrap::ClapTrap(const ClapTrap &original) {
	std::cout << DARK_INDIGO << "claptrap copy constructor" << std::endl;
	_name = original.getName();
	_attack_damage = original.getAttackDamage();
	_energy_points = original.getEnergyPoints();
	_hit_points = original.getHitpoints();
}

ClapTrap::~ClapTrap() {
	std::cout << DARK_RED << "claptrap " << _name << " destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &original) {
	std::cout << DARK_YELLOW << "claptrap assignation operator" << std::endl;
	_name = original.getName();
	_attack_damage = original.getAttackDamage();
	_energy_points = original.getEnergyPoints();
	_hit_points = original.getHitpoints();
	return *this;
}

// methods
void ClapTrap::attack(std::string const &target) {
	std::cout << DARK_RED << _name << " attacks " << target << " causing " << _attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << DARK_RED << _name << " takes " << amount << " points of damage!" << std::endl;
	_hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << DARK_GREEN << _name << " is repaired for " << amount << " points of health!" << std::endl;
	_hit_points += amount;
}

// getters
std::string ClapTrap::getName() const {
	return _name;
}

unsigned int ClapTrap::getAttackDamage() const {
	return _attack_damage;
}

unsigned int ClapTrap::getEnergyPoints() const {
	return _energy_points;
}

unsigned int ClapTrap::getHitpoints() const {
	return _hit_points;
}