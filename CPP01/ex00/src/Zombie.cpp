/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:12 by erian             #+#    #+#             */
/*   Updated: 2025/01/20 11:48:18 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : _name(name) {}

void Zombie::Announce() {
	std::cout << DARKBLUE << _name << BLUE << ": BraiiiiiiinnnzzzZ...\n" << NC; 
}

Zombie::~Zombie() {
	std::cout << RED << "Zombie: " << DARKBLUE << _name << RED << " die\n" << NC;
}
