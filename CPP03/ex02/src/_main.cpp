/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:22:39 by erian             #+#    #+#             */
/*   Updated: 2025/02/22 11:26:28 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main() {
	FragTrap fragtrap("fragtrap_00");
	ClapTrap claptrap("claptrap_00");

	fragtrap.attack("claptrap_00");
	claptrap.takeDamage(30);
	claptrap.beRepaired(30);
	fragtrap.highFivesGuys();

	return 0;
}