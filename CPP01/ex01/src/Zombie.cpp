/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:13:03 by erian             #+#    #+#             */
/*   Updated: 2025/02/18 12:07:29 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie( std::string name ) : _name(name) {}

void Zombie::Announce() {
	std::cout << DARK_BLUE << _name << DARK_GREEN << ": BraiiiiiiinnnzzzZ..." << NC << std::endl; 
}

Zombie::~Zombie() {
	std::cout << DARK_BLUE << _name << DARK_RED << ": executed" << NC << std::endl;
	usleep(77777);
}