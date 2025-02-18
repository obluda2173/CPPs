/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:12 by erian             #+#    #+#             */
/*   Updated: 2025/02/18 11:52:52 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie( std::string name ) : _name(name) {}

void Zombie::Announce() {
	std::cout << DARK_BLUE << _name << BLUE << ": BraiiiiiiinnnzzzZ..." << NC << std::endl; 
}

Zombie::~Zombie() {
	std::cout << DARK_BLUE << _name << DARK_RED << ": died" << NC << std::endl;
}