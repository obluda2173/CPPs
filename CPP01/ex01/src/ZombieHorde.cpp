/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:08:31 by erian             #+#    #+#             */
/*   Updated: 2025/01/20 12:12:45 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *ZombieHorde(int horde_size, std::string name) {
	Zombie *zombies = new Zombie[horde_size];

	for (int i = 0; i < horde_size; i++)
		zombies[i] = Zombie(name);
	return zombies;
}