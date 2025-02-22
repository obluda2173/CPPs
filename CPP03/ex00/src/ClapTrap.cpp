/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:22:41 by erian             #+#    #+#             */
/*   Updated: 2025/02/22 11:07:19 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << DARK_GREEN << "claptrap default constructor" << NC << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name) {
	std::cout << DARK_MAGENTA << "claptrap " << name << " created" << NC << std::endl;
	_attack_damage = 0;
	_energy_points = 10;
	_hit_points = 10;
}

ClapTrap::ClapTrap(const ClapTrap &original) {
	std::cout << DARK_INDIGO << "claptrap copy constructor" << NC << std::endl;
	_name = original.getName();
	_attack_damage = original.getAttackDamage();
	_energy_points = original.getEnergyPoints();
	_hit_points = original.getHitpoints();
}

ClapTrap::~ClapTrap() {
	std::cout << DARK_RED << "claptrap " << _name << " destroyed" << NC << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &original) {
	std::cout << DARK_YELLOW << "claptrap assignation operator" << NC << std::endl;
	_name = original.getName();
	_attack_damage = original.getAttackDamage();
	_energy_points = original.getEnergyPoints();
	_hit_points = original.getHitpoints();
	return *this;
}

// methods
void ClapTrap::attack(const std::string &target) {
	std::cout << DARK_RED << _name << " attacks " << target << " causing " << _attack_damage << " points of damage!" << NC << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << DARK_RED << _name << " takes " << amount << " points of damage!" << NC << std::endl;
	_hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energy_points == 0) {
		std::cout << RED << _name << " can not be repaired! energy points: " << _energy_points << NC << std::endl;
		return;
	}
	_energy_points--;
	std::cout << DARK_GREEN << _name << " is repaired for " << amount << " points of health!" << NC << std::endl;
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