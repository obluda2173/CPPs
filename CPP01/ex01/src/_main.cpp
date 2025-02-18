/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:00:50 by erian             #+#    #+#             */
/*   Updated: 2025/02/18 12:13:12 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie *horde = zombieHorde(11, "Wagner");

	for (int i = 0; i < 11; i++) {
		horde[i].Announce();
		usleep(77777);
	}

	delete [] horde;
	return 0;
}