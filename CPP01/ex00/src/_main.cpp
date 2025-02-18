/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:25:04 by erian             #+#    #+#             */
/*   Updated: 2025/02/18 11:02:25 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie *zombie = newZombie("Onishchenko");
	zombie->Announce();
	
	delete(zombie);

	randomChump("Wagner");

	return 0;
}