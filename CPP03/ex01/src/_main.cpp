/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:22:39 by erian             #+#    #+#             */
/*   Updated: 2025/02/21 12:19:37 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ScavTrap slavtrap_01("slavtrap_01");
	ClapTrap claptrap_01("claptrap_01");
	
	slavtrap_01.guardGate();
	slavtrap_01.attack("claptrap_01");
	claptrap_01.takeDamage(20);
	claptrap_01.beRepaired(20);

	return 0;
}