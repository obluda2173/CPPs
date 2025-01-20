/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:24:44 by erian             #+#    #+#             */
/*   Updated: 2025/01/20 12:05:02 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <unistd.h>

#include "Colors.hpp"

class Zombie {
	private:
	std::string _name;

	public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	
	void Announce();
};

Zombie* ZombieHorde(int N, std::string name);
