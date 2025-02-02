/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:13:03 by erian             #+#    #+#             */
/*   Updated: 2025/02/01 12:30:42 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

using std::cout;
using std::endl;

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : _name(name) {}

void Zombie::Announce() {
	cout << DARKBLUE << _name << BLUE << ": BraiiiiiiinnnzzzZ...\n" << NC; 
}

Zombie::~Zombie() {
	cout << RED << "Zombie: " << DARKBLUE << _name << RED << " die\n" << NC;
	usleep(50000);
}