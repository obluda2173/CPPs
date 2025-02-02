/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:25:04 by erian             #+#    #+#             */
/*   Updated: 2025/02/01 12:29:20 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie *zombie = newZombie("Zakharchenko");
	zombie->Announce();
	
	randomChump("Wagner");
	randomChump("Onishchenko");

	delete(zombie);
	return 0;
}