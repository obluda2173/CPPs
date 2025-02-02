/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:00:50 by erian             #+#    #+#             */
/*   Updated: 2025/02/01 12:30:57 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int horde_size = 10;
	Zombie *horde = ZombieHorde(horde_size, "Zakharchenko");

	for (int i = 0; i < horde_size; i++) {
		horde[i].Announce();
		usleep(50000);
	}
	delete [] horde;
	return (0);
}