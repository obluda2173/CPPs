/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erian <erian@student.42>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:24:44 by erian             #+#    #+#             */
/*   Updated: 2025/01/20 11:49:50 by erian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

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

Zombie *NewZombie(std::string name);
void RandomChump(std::string name);