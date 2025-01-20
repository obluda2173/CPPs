/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:25:04 by erian             #+#    #+#             */
/*   Updated: 2025/01/20 11:58:47 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie *zombie = NewZombie("Zakharchenko");
	zombie->Announce();
	zombie->Announce();
	
	RandomChump("Wagner");
	RandomChump("Onishchenko");

	delete(zombie);
	return 0;
}
